#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QLabel>
#include <QFont>
#include <QList>
#include <QAction>
#include <QByteArray>
#include <QIcon>
#include "canvas.h"
#include "components/colordialog.h"
#include "components/widthdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class App; }
QT_END_NAMESPACE

class App : public QMainWindow
{
    Q_OBJECT

public:
    App(QWidget *parent = nullptr);
    ~App();

    void initCanvas();
    void createStatusBar();
    void createAction();
private:
    /* UI Qt framework */
    Ui::App *ui;

    /* Draw and catch event */
    Canvas* canvas;
    QString currentMessage;

    /* Current tool name */
    QLabel* _toolPicLabel;
    QLabel* _toolNameLabel;
    /* Current tool width */
    QLabel* _toolWidthLabel;

    QList<QAction*> _saveActs;

    /* Use new tool from clicked button */
    void useTool(ToolType type);
    void saveFile(const QByteArray &format);

/* Below is Qt framework */
private slots:
    void on_actionClear_triggered();
    void on_actionExit_triggered();
    void on_actionBrush_triggered();
    void on_actionLine_triggered();
    void on_actionRectangle_triggered();
    void on_actionEllipse_triggered();
    void on_actionWidth_triggered();
    void on_actionColor_triggered();
    void on_actionInfo_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionSave_triggered();
    void on_colorBtn_clicked();
    void on_clearBtn_clicked();
    void on_widthBtn_clicked();
    void on_penBtn_clicked();
    void on_lineBtn_clicked();
    void on_rectBtn_clicked();
    void on_circleBtn_clicked();
    void on_eraserBtn_clicked();
    void on_brushBtn_clicked();
    void on_actionOpen_triggered();
    void save();
    void on_bucketBtn_clicked();
    void on_actionDark_triggered();
    void on_actionLight_triggered();
};
#endif // APP_H
