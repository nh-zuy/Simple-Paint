#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPoint>
#include <QString>
#include <QStack>
#include <QColor>
#include <QSize>
#include <QVector>
#include <QImage>
#include <QMouseEvent>
#include <QPaintEvent>
#include <memory>
#include "toolmanager.h"

/**
 * Area for drawing, handling and making image, graphic object, ...
 *
 * @brief The Canvas class
 */
class Canvas : public QWidget
{
    Q_OBJECT
private:
    /* Orginal image */
    QImage _originalImage;
    /* Buffer image */
    QImage _image;
    /* Used tool */
    QVector<std::shared_ptr<ITool>>_tools;
    /* Store removed tool */
    QStack<std::shared_ptr<ITool>> _memoryStack;
    /* Manager tool */
    ToolManager* _toolManager;
public:
    explicit Canvas(QWidget *parent = NULL, ToolManager* manager = NULL);
    ~Canvas() = default;

    /* Resize current image to size */
    void resizeImage(QImage* image, const QSize& size);
    /* Open new image */
    void openImage(const QString& filename);
    /* Save current image */
    void saveImage(const QString& filename);
    /* Save with specific format */
    void saveImage(const QString& filename, const char* format);
    /* Set up tool manager */
    void setToolManager(ToolManager& manager);
    /* Set background with color */
    void setBackground(const QColor &);
    /* Flood fill algorithm */
    void floodFill(const QPoint& point, const QColor& color);
    /* Clear image */
    void clear();
    void undo();
    void redo();

protected:
    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
};

#endif // CANVAS_H
