#include <QQueue>
#include <QDebug>
#include <iostream>
#include <memory>
#include "canvas.h"

/**
 * @brief Canvas::Canvas
 * @param parent
 * @param manager
 */
Canvas::Canvas(QWidget *parent, ToolManager* manager)
    :QWidget(parent),
     _originalImage(this->size(), QImage::Format_RGB32),
     _image(this->size(), QImage::Format_RGB32),
     _toolManager(manager)
{
    this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    this->resize(200, 200);
    this->setBackground(Qt::white);
}

/**
 * @brief Canvas::resizeImage
 * @param image
 * @param size
 */
void Canvas::resizeImage(QImage *image, const QSize &size)
{
    if (image->size() == size) {
        return;
    };

    QImage newImage(size, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

/**
 * @brief Canvas::openImage
 * @param filename
 */
void Canvas::openImage(const QString &filename)
{
    QImage image;

    if (!image.load(filename)) {
        QMessageBox::warning(this, "Oops!", "Can't open file @@");
        return;
    };

    QSize size = image.size().expandedTo(this->size());
    this->resizeImage(&image, size);
    this->_originalImage = image;
    this->_image = image;

    this->clear();
    this->update();
}

/**
 * @brief Canvas::saveImage
 * @param filename
 */
void Canvas::saveImage(const QString &filename)
{
    QPainter painter(&this->_image);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
    /* Tool draw by each other */
    for(std::shared_ptr<ITool> tool : this->_tools) {
        tool->draw(&painter);
    };

    QImage image = this->_image;
    this->resizeImage(&image, this->size());

    if (!image.save(filename)) {
        QMessageBox::warning(this, "Oops!", "Unable to save file @@");
    };
}

/**
 * @brief Canvas::saveImage
 * @param filename
 * @param format
 */
void Canvas::saveImage(const QString &filename, const char *format)
{
    QPainter painter(&this->_image);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
    /* Tool draw by each other */
    for(std::shared_ptr<ITool> tool : this->_tools) {
        tool->draw(&painter);
    };

    QImage image = this->_image;
    this->resizeImage(&image, this->size());

    if (!image.save(filename, format)) {
        QMessageBox::warning(this, "Oops!", "Unable to save file @@");
    };
}

/**
 * @brief Canvas::paintEvent
 * @param event
 */
void Canvas::paintEvent(QPaintEvent * event)
{
    this->_image = this->_originalImage;
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
    QRect dirty = event->rect();
    painter.drawImage(dirty, this->_image, dirty);

    /**
     * When use tool to draw new shape,
     * we draw in QImage.
     * After all, we must to paint this image in Canvas.
     */
    for(std::shared_ptr<ITool> tool : this->_tools) {
        tool->draw(&painter);
    };
}

/**
 * @brief Canvas::resizeEvent
 * @param event
 */
void Canvas::resizeEvent(QResizeEvent *event)
{
    if (this->width() > this->_image.width() || this->height() > this->_image.height()) {
        int newWidth = qMax(this->width() + 128, this->_image.width());
        int newHeight = qMax(this->height() + 128, this->_image.height());
        this->resizeImage(&this->_image, QSize(newWidth, newHeight));
        this->resizeImage(&this->_originalImage, QSize(newWidth, newHeight));
        this->update();
    };

    QWidget::resizeEvent(event);
}

/**
 * @brief Canvas::mousePressEvent
 * @param event
 */
void Canvas::mousePressEvent(QMouseEvent * event)
{
    if (event->buttons() & Qt::LeftButton)  {
        this->_toolManager->startDraw(event->pos());

        if (this->_toolManager->currentToolType() == ToolType::Bucket) {
            this->floodFill(event->pos(), this->_toolManager->currentColor());
        };

        this->_tools.push_back(this->_toolManager->currentTool());
        update();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent * event)
{
    if (event->buttons() & Qt::LeftButton){
        this->_toolManager->endDraw(event->pos());
        update();
    }
}

void Canvas::setBackground(const QColor &color)
{
    this->_originalImage.fill(color);
    this->_image.fill(color);
}

void Canvas::floodFill(const QPoint &point, const QColor &color) {
    /*
     *  Befor all,
     *  We need to appy all change in Canvas into image
     */
    QPainter painter(&this->_image);
    for(std::shared_ptr<ITool> tool : this->_tools) {
        tool->draw(&painter);
    };

    /* Now, let's get started
     * First, need to init start point
     */
    QPoint startPoint = point;
    QColor originalColor = this->_image.pixelColor(startPoint);

    /* Boundary is the image [0,0] -> [width, height]
     * Draw will be flooded from start point
     * to all pixels has the same color
     * Or, all the canvas */
    int w = this->_image.width();
    int h = this->_image.height();

    /* Use DFS algrithm to implement the Flood Fill */
    QStack<QPoint> pixels;
    pixels.push(startPoint);
    while (!pixels.isEmpty()) {
        /* Get new point from stack */
        QPoint newPoint = pixels.pop();
        int x = newPoint.x();
        int y = newPoint.y();

        /* If point coordiate is out of boudary
         * Just ignore and continue travel
        */
        if (x < 0 || x >= w || y < 0 || y >= h) {
            continue;
        };

        /*
         * If not,
         * Get it's color
         * and use it to compare with neighbor pixel
         * This can help we knowing if can reach to another pixel or not.
         */
        QColor newColor = this->_image.pixelColor(newPoint);

        /* If it has the same color with the start pixel */
        if (newColor == originalColor) {
            /* Mark it
             * And save point to the path
            */
            this->_image.setPixelColor(newPoint, color);
            this->_toolManager->endDraw(newPoint);

            /*
             * Travel all the neighbor pixels
             * And DFS it
             */
            pixels.push(QPoint(x - 1, y));
            pixels.push(QPoint(x + 1, y));
            pixels.push(QPoint(x, y - 1));
            pixels.push(QPoint(x, y + 1));
        };
    };
}

void Canvas::undo()
{
    if (!this->_tools.empty()){
        /* Get the last tool */
        std::shared_ptr<ITool> undoValue = this->_tools.back();
        this->_memoryStack.push(undoValue);
        this->_tools.pop_back();

        /* Repaint all tool new in the image */
        this->_image = this->_originalImage;

        update();
    }
}

void Canvas::redo()
{
    if (!this->_memoryStack.empty()){
        /* Get the last removed tool */
        std::shared_ptr<ITool> redoValue = this->_memoryStack.pop();
        _tools.append(redoValue);

        /* Repaint all the tool in image */
        this->_image = this->_originalImage;

        update();
    }
}

void Canvas::setToolManager(ToolManager &manager) {
    this->_toolManager = &manager;
}

void Canvas::clear()
{
    this->_tools.clear();
    this->_memoryStack.clear();

    update();
}

