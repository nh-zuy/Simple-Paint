/********************************************************************************
** Form generated from reading UI file 'app.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_H
#define UI_APP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_App
{
public:
    QAction *actionClear;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSave;
    QAction *actionBrush;
    QAction *actionLine;
    QAction *actionRectangle;
    QAction *actionEllipse;
    QAction *actionColor;
    QAction *actionWidth;
    QAction *actionInfo;
    QAction *actionOpen;
    QAction *actionDark;
    QAction *actionLight;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *saveAsMenu;
    QMenu *menuOptions;
    QMenu *menuThemes;
    QMenu *menuAbout;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QPushButton *penBtn;
    QPushButton *brushBtn;
    QPushButton *eraserBtn;
    QPushButton *bucketBtn;
    QPushButton *lineBtn;
    QPushButton *rectBtn;
    QPushButton *circleBtn;
    QPushButton *colorBtn;
    QPushButton *widthBtn;
    QPushButton *clearBtn;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *App)
    {
        if (App->objectName().isEmpty())
            App->setObjectName(QString::fromUtf8("App"));
        App->resize(733, 480);
        actionClear = new QAction(App);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon);
        actionExit = new QAction(App);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons8-exit-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionUndo = new QAction(App);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons8-undo-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon2);
        actionRedo = new QAction(App);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons8-redo-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon3);
        actionSave = new QAction(App);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/icons8-save-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        actionBrush = new QAction(App);
        actionBrush->setObjectName(QString::fromUtf8("actionBrush"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons8-cosmetic-brush-52.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBrush->setIcon(icon5);
        actionLine = new QAction(App);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLine->setIcon(icon6);
        actionRectangle = new QAction(App);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle->setIcon(icon7);
        actionEllipse = new QAction(App);
        actionEllipse->setObjectName(QString::fromUtf8("actionEllipse"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEllipse->setIcon(icon8);
        actionColor = new QAction(App);
        actionColor->setObjectName(QString::fromUtf8("actionColor"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/palette.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionColor->setIcon(icon9);
        actionWidth = new QAction(App);
        actionWidth->setObjectName(QString::fromUtf8("actionWidth"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/width.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWidth->setIcon(icon10);
        actionInfo = new QAction(App);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon11);
        actionOpen = new QAction(App);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/icons8-add-file-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon12);
        actionDark = new QAction(App);
        actionDark->setObjectName(QString::fromUtf8("actionDark"));
        actionDark->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/icons8-single-page-mode-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDark->setIcon(icon13);
        actionLight = new QAction(App);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        actionLight->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/icons8-single-page-mode-light-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLight->setIcon(icon14);
        centralWidget = new QWidget(App);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        App->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(App);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 733, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        saveAsMenu = new QMenu(menuFile);
        saveAsMenu->setObjectName(QString::fromUtf8("saveAsMenu"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuThemes = new QMenu(menuOptions);
        menuThemes->setObjectName(QString::fromUtf8("menuThemes"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        App->setMenuBar(menuBar);
        toolBar = new QToolBar(App);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        App->addToolBar(Qt::BottomToolBarArea, toolBar);
        dockWidget = new QDockWidget(App);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy);
        dockWidget->setMinimumSize(QSize(120, 80));
        dockWidget->setMaximumSize(QSize(120, 300));
        dockWidget->setAutoFillBackground(true);
        dockWidget->setFeatures(QDockWidget::DockWidgetClosable);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        penBtn = new QPushButton(dockWidgetContents);
        penBtn->setObjectName(QString::fromUtf8("penBtn"));
        penBtn->setGeometry(QRect(10, 10, 46, 34));
        penBtn->setFocusPolicy(Qt::StrongFocus);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/icons8-pen-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        penBtn->setIcon(icon15);
        penBtn->setIconSize(QSize(28, 28));
#ifndef QT_NO_SHORTCUT
        penBtn->setShortcut(QString::fromUtf8(""));
#endif // QT_NO_SHORTCUT
        penBtn->setCheckable(false);
        brushBtn = new QPushButton(dockWidgetContents);
        brushBtn->setObjectName(QString::fromUtf8("brushBtn"));
        brushBtn->setGeometry(QRect(60, 10, 46, 34));
        brushBtn->setIcon(icon5);
        brushBtn->setIconSize(QSize(28, 28));
        brushBtn->setCheckable(false);
        brushBtn->setChecked(false);
        eraserBtn = new QPushButton(dockWidgetContents);
        eraserBtn->setObjectName(QString::fromUtf8("eraserBtn"));
        eraserBtn->setGeometry(QRect(10, 50, 46, 34));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/icons8-erase-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraserBtn->setIcon(icon16);
        eraserBtn->setIconSize(QSize(28, 28));
        eraserBtn->setCheckable(false);
        bucketBtn = new QPushButton(dockWidgetContents);
        bucketBtn->setObjectName(QString::fromUtf8("bucketBtn"));
        bucketBtn->setGeometry(QRect(60, 50, 46, 34));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/icons8-fill-color-52.png"), QSize(), QIcon::Normal, QIcon::Off);
        bucketBtn->setIcon(icon17);
        bucketBtn->setIconSize(QSize(28, 28));
        bucketBtn->setCheckable(false);
        lineBtn = new QPushButton(dockWidgetContents);
        lineBtn->setObjectName(QString::fromUtf8("lineBtn"));
        lineBtn->setGeometry(QRect(10, 100, 46, 34));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/icons8-line-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineBtn->setIcon(icon18);
        lineBtn->setIconSize(QSize(28, 28));
        lineBtn->setCheckable(false);
        rectBtn = new QPushButton(dockWidgetContents);
        rectBtn->setObjectName(QString::fromUtf8("rectBtn"));
        rectBtn->setGeometry(QRect(60, 100, 46, 34));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/icons8-rectangle-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectBtn->setIcon(icon19);
        rectBtn->setIconSize(QSize(28, 28));
        rectBtn->setCheckable(false);
        circleBtn = new QPushButton(dockWidgetContents);
        circleBtn->setObjectName(QString::fromUtf8("circleBtn"));
        circleBtn->setGeometry(QRect(10, 140, 46, 34));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/images/icons8-circle-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        circleBtn->setIcon(icon20);
        circleBtn->setIconSize(QSize(28, 28));
        circleBtn->setCheckable(false);
        colorBtn = new QPushButton(dockWidgetContents);
        colorBtn->setObjectName(QString::fromUtf8("colorBtn"));
        colorBtn->setGeometry(QRect(10, 190, 46, 34));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/images/icons8-color-mode-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorBtn->setIcon(icon21);
        colorBtn->setIconSize(QSize(28, 28));
        widthBtn = new QPushButton(dockWidgetContents);
        widthBtn->setObjectName(QString::fromUtf8("widthBtn"));
        widthBtn->setGeometry(QRect(60, 190, 46, 34));
        widthBtn->setIcon(icon10);
        widthBtn->setIconSize(QSize(28, 28));
        clearBtn = new QPushButton(dockWidgetContents);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
        clearBtn->setGeometry(QRect(10, 230, 46, 34));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/images/icons8-cls-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearBtn->setIcon(icon22);
        clearBtn->setIconSize(QSize(28, 28));
        clearBtn->setCheckable(false);
        dockWidget->setWidget(dockWidgetContents);
        App->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        toolBar_2 = new QToolBar(App);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        App->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(saveAsMenu->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuOptions->addAction(menuThemes->menuAction());
        menuThemes->addAction(actionDark);
        menuThemes->addAction(actionLight);
        menuAbout->addAction(actionInfo);
        toolBar_2->addAction(actionOpen);
        toolBar_2->addAction(actionSave);
        toolBar_2->addSeparator();
        toolBar_2->addAction(actionUndo);
        toolBar_2->addAction(actionRedo);
        toolBar_2->addSeparator();
        toolBar_2->addAction(actionExit);

        retranslateUi(App);

        QMetaObject::connectSlotsByName(App);
    } // setupUi

    void retranslateUi(QMainWindow *App)
    {
        App->setWindowTitle(QApplication::translate("App", "MainWindow", nullptr));
        actionClear->setText(QApplication::translate("App", "&Clear", nullptr));
        actionExit->setText(QApplication::translate("App", "&Exit", nullptr));
        actionUndo->setText(QApplication::translate("App", "&Undo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("App", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("App", "&Redo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("App", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("App", "&Save", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("App", "Save file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("App", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionBrush->setText(QApplication::translate("App", "&Brush", nullptr));
        actionLine->setText(QApplication::translate("App", "&Line", nullptr));
        actionRectangle->setText(QApplication::translate("App", "&Rectangle", nullptr));
        actionEllipse->setText(QApplication::translate("App", "&Ellipse", nullptr));
        actionColor->setText(QApplication::translate("App", "&Color", nullptr));
#ifndef QT_NO_TOOLTIP
        actionColor->setToolTip(QApplication::translate("App", "Select color to draw", nullptr));
#endif // QT_NO_TOOLTIP
        actionWidth->setText(QApplication::translate("App", "&Width", nullptr));
#ifndef QT_NO_TOOLTIP
        actionWidth->setToolTip(QApplication::translate("App", "Set line width", nullptr));
#endif // QT_NO_TOOLTIP
        actionInfo->setText(QApplication::translate("App", "&Info", nullptr));
        actionOpen->setText(QApplication::translate("App", "Open", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("App", "New file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("App", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionDark->setText(QApplication::translate("App", "Dark", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDark->setToolTip(QApplication::translate("App", "Dark Mode", nullptr));
#endif // QT_NO_TOOLTIP
        actionLight->setText(QApplication::translate("App", "Light", nullptr));
#ifndef QT_NO_TOOLTIP
        actionLight->setToolTip(QApplication::translate("App", "Light Mode", nullptr));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("App", "&File", nullptr));
        saveAsMenu->setTitle(QApplication::translate("App", "Save as ...", nullptr));
        menuOptions->setTitle(QApplication::translate("App", "&Home", nullptr));
        menuThemes->setTitle(QApplication::translate("App", "Themes", nullptr));
        menuAbout->setTitle(QApplication::translate("App", "&About", nullptr));
        toolBar->setWindowTitle(QApplication::translate("App", "toolBar", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("App", "Paint Tool", nullptr));
#ifndef QT_NO_TOOLTIP
        penBtn->setToolTip(QApplication::translate("App", "<html><head/><body><p>Pen</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        penBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        brushBtn->setToolTip(QApplication::translate("App", "<html><head/><body><p>Brush</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        brushBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        eraserBtn->setToolTip(QApplication::translate("App", "<html><head/><body><p>Eraser</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        eraserBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        bucketBtn->setToolTip(QApplication::translate("App", "<html><head/><body><p>Fill Bucket</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        bucketBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineBtn->setToolTip(QApplication::translate("App", "<html><head/><body><p>Line</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        lineBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        rectBtn->setToolTip(QApplication::translate("App", "<html><head/><body><p>Rectangle</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        rectBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        circleBtn->setToolTip(QApplication::translate("App", "<html><head/><body><p>Circle</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        circleBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        colorBtn->setToolTip(QApplication::translate("App", "<html><head/><body><p>Color Panel</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        colorBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        widthBtn->setToolTip(QApplication::translate("App", "<html><head/><body><p>Width size</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        widthBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        clearBtn->setToolTip(QApplication::translate("App", "<html><head/><body><p>Clear screen</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        clearBtn->setText(QString());
        toolBar_2->setWindowTitle(QApplication::translate("App", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class App: public Ui_App {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
