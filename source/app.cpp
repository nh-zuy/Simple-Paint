#include <QWidget>
#include <QHBoxLayout>
#include <QByteArray>
#include <QImageWriter>
#include <memory>
#include "app.h"
#include "ui_app.h"

/**
 * @brief App::App
 * @param parent
 */
App::App(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);

    /* Set up */
    this->initCanvas();
    this->createStatusBar();
    this->createAction();

    /* Set opening size */
    this->setWindowTitle("Simple paint");
    this->resize(800, 600);
    this->canvas->setCursor(QCursor(QPixmap(tr(":/images/icons8-pen-24.png")), 0, 0));
}

/**
 * @brief App::~App
 */
App::~App()
{
    delete ui;
}

void App::initCanvas()
{
    ToolManager& toolManager = ToolManager::getInstance();
    canvas = new Canvas(this, &toolManager);
    setCentralWidget(new QWidget(this));
    QWidget* central = this->centralWidget();
    central->setLayout(new QHBoxLayout);
    central->layout()->addWidget(canvas);
}

void App::createStatusBar() {
    this->_toolPicLabel = new QLabel("");
    this->_toolNameLabel = new QLabel(" Pen");
    this->_toolWidthLabel = new QLabel("\tSize: 3");
    auto font = _toolNameLabel->font();
    font.setBold(true);
    font.setPointSize(8);
    this->_toolPicLabel->setFont(font);
    this->_toolNameLabel->setFont(font);
    this->_toolWidthLabel->setFont(font);
    this->_toolPicLabel->setPixmap(QPixmap(tr(":/images/icons8-pen-24.png")));
    ui->toolBar->addWidget(this->_toolPicLabel);
    ui->toolBar->addWidget(this->_toolNameLabel);
    ui->toolBar->addWidget(this->_toolWidthLabel);

    ui->actionLight->setChecked(true);
}

void App::createAction()
{
    foreach (QByteArray format, QImageWriter::supportedImageFormats()) {
        QString text = tr("*.%1").arg(QString(format).toLower());
        // Create an action for each file format
        QAction *action = new QAction(text, this);
        // Set an action for each file format
        action->setData(format);
        action->setIcon(QIcon(QPixmap(tr(":/images/icons8-image-32.png"))));
        // When clicked call MainWindow::save()
        connect(action, SIGNAL(triggered()), this, SLOT(save()));
        // Attach each file format option menu item to Save As
        this->_saveActs.append(action);
    };

    foreach (QAction* action, this->_saveActs) {
        ui->saveAsMenu->addAction(action);
    };
}

/**
 * @brief App::useTool
 * @param type
 */
void App::useTool(ToolType type)
{
    ToolManager& toolManager = ToolManager::getInstance();
    toolManager.setCurrentTool(type);
}

void App::save()
{
    QAction* action = qobject_cast<QAction*>(this->sender());
    QByteArray format = action->data().toByteArray();
    this->saveFile(format);
}
void App::saveFile(const QByteArray &format)
{
    QString path = QDir::currentPath() + "/untitle." + format;
    QString filename = QFileDialog::getSaveFileName(this, tr("Save as ..."), path, tr("%1 Files (*.%2);;All Files (*)").arg(QString::fromLatin1(format.toUpper())).arg(QString::fromLatin1(format)));
    if (filename.isEmpty()) {
        return;
    };
    this->canvas->saveImage(filename, format.constData());
}

/**
 * @brief App::on_actionClear_triggered
 */
void App::on_actionClear_triggered()
{
    //this->canvas->setBackground(Qt::white);
    this->canvas->clear();
    this->update();
}

/**
 * @brief App::on_actionExit_triggered
 */
void App::on_actionExit_triggered()
{
    this->close();
}

/**
 * @brief App::on_actionBrush_triggered
 */
void App::on_actionBrush_triggered()
{
    this->_toolPicLabel->setPixmap(QPixmap(tr(":/images/icons8-pen-24.png")));
    _toolNameLabel->setText(" Pen");
    this->useTool(ToolType::Pen);
    this->canvas->setCursor(QCursor(QPixmap(tr(":/images/icons8-pen-24.png")), 0, 0));
}

/**
 * @brief App::on_actionLine_triggered
 */
void App::on_actionLine_triggered()
{
    _toolNameLabel->setText(" Line");
    this->useTool(ToolType::Line);
}

void App::on_actionRectangle_triggered()
{
    _toolNameLabel->setText(" Rectangle");
    this->useTool(ToolType::Rectangle);
}

void App::on_actionEllipse_triggered()
{
    _toolNameLabel->setText(" Circle");
    this->useTool(ToolType::Circle);
}

void App::on_actionWidth_triggered()
{
    ToolManager& manager = ToolManager::getInstance();

    std::shared_ptr<WidthDialog> dialog = std::make_shared<WidthDialog>(this->canvas);
    dialog->setValue(manager.currentWidth());

    if (dialog->exec() == QDialog::Accepted)
    {
        int width = dialog->getValue();
        manager.setCurrentWidth(width);

        this->_toolWidthLabel->setText("\tSize: " + QString::number(width));
    };
}

void App::on_actionColor_triggered()
{
    ToolManager& toolManager = ToolManager::getInstance();

    std::shared_ptr<ColorDialog> dialog = std::make_shared<ColorDialog>(this->canvas);
    dialog->setColor(toolManager.currentColor());
    QColor color = dialog->chooseColor();

    if (color.isValid()) {
        toolManager.setCurrentColor(color);
    };
}

void App::on_actionInfo_triggered()
{
    QMessageBox::about(this, tr("About"), tr("---------------------------- Simple paint --------------------------------\n\n"
                                             "Author: nh-zuy\n"
                                             "Github: https://github.com/nh-zuy\n\n"
                                             "Functionnals:\n"
                                             "  1. Painting whatever you want and fill color those.\n"
                                             "  2. Open and save image.\n"
                                             "  3. Chang dark theme.\n\n"
                                             "Our vision: 'With this simple paint, you can do nothing, make\n"
                                             "your dream come fail and realize it suck' =))"));
}

void App::on_actionUndo_triggered()
{
    this->canvas->undo();
}

void App::on_actionRedo_triggered()
{
    this->canvas->redo();
}

void App::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open New File"), QDir::currentPath());

    if (!filename.isEmpty()) {
        this->canvas->openImage(filename);
    };
}

void App::on_actionSave_triggered()
{
    QString path = QDir::currentPath() + "/untitle.jpg";
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save as ..."), path,
                                                    "JPEG(*.jpg;*.jpeg;*.jpe);;All Files (*)");

    if (fileName.isEmpty()) {
        return;
    };

    return this->canvas->saveImage(fileName);
}

void App::on_colorBtn_clicked()
{
    emit on_actionColor_triggered();
}

void App::on_clearBtn_clicked()
{
    emit on_actionClear_triggered();
}

void App::on_widthBtn_clicked()
{
    emit on_actionWidth_triggered();
}

void App::on_penBtn_clicked()
{
    emit on_actionBrush_triggered();
}

void App::on_lineBtn_clicked()
{
    emit on_actionLine_triggered();
    this->_toolPicLabel->setPixmap(QPixmap(tr(":/images/icons8-line-24.png")));
    this->canvas->setCursor(QCursor(QPixmap(tr(":/images/icons8-line-24.png")), 0, 0));
}

void App::on_rectBtn_clicked()
{
    emit on_actionRectangle_triggered();
    this->_toolPicLabel->setPixmap(QPixmap(tr(":/images/icons8-rounded-rectangle-stroked-24.png")));
    this->canvas->setCursor(QCursor(QPixmap(tr(":/images/icons8-rounded-rectangle-stroked-24.png")), 0, 0));
}

void App::on_circleBtn_clicked()
{
    emit on_actionEllipse_triggered();
    this->_toolPicLabel->setPixmap(QPixmap(tr(":/images/icons8-circle-24.png")));
    this->canvas->setCursor(QCursor(QPixmap(tr(":/images/icons8-circle-24.png")), 0, 0));
}

void App::on_eraserBtn_clicked()
{
    _toolNameLabel->setText(" Eraser");
    this->useTool(ToolType::Eraser);
    this->_toolPicLabel->setPixmap(QPixmap(tr(":/images/icons8-eraser-24.png")));
    this->canvas->setCursor(QCursor(QPixmap(tr(":/images/icons8-eraser-24.png")), 0, 0));
}

void App::on_brushBtn_clicked()
{
    _toolNameLabel->setText(" Brush");
    this->useTool(ToolType::Brush);
    this->_toolPicLabel->setPixmap(QPixmap(tr(":/images/icons8-cosmetic-brush-24.png")));
    this->canvas->setCursor(QCursor(QPixmap(tr(":/images/icons8-cosmetic-brush-24.png")), 0, 0));
}


void App::on_bucketBtn_clicked()
{
    _toolNameLabel->setText(" Bucket");
    this->useTool(ToolType::Bucket);
    this->_toolPicLabel->setPixmap(QPixmap(tr(":/images/icons8-fill-color-26.png")));
    this->canvas->setCursor(QCursor(QPixmap(tr(":/images/icons8-fill-color-26.png")), 0, 0));
}

void App::on_actionDark_triggered()
{
    QFile file(":/PicPax.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet { QLatin1String(file.readAll()) };
    setStyleSheet(styleSheet);
    ui->actionDark->setChecked(true);
    ui->actionLight->setChecked(false);
}

void App::on_actionLight_triggered()
{
    setStyleSheet("");
    ui->actionLight->setChecked(true);
    ui->actionDark->setChecked(false);
}
