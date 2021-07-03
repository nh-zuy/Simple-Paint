QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstracts/itool.cpp \
    abstracts/shape.cpp \
    canvas.cpp \
    components/colordialog.cpp \
    components/widthdialog.cpp \
    main.cpp \
    app.cpp \
    shapes/circle.cpp \
    shapes/line.cpp \
    shapes/rectangle.cpp \
    toolmanager.cpp \
    tools/brush.cpp \
    tools/bucket.cpp \
    tools/eraser.cpp \
    tools/pen.cpp

HEADERS += \
    abstracts/itool.h \
    abstracts/shape.h \
    app.h \
    canvas.h \
    components/colordialog.h \
    components/widthdialog.h \
    shapes/circle.h \
    shapes/line.h \
    shapes/rectangle.h \
    toolmanager.h \
    tools/brush.h \
    tools/bucket.h \
    tools/eraser.h \
    tools/pen.h \
    tooltype.h

FORMS += \
    app.ui \
    components/widthdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
