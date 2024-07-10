QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gift.cpp \
    giftshop.cpp \
    main.cpp \
    mainwindow.cpp \
    manage.cpp \
    picbutton.cpp \
    taskform.cpp \
    tasksetting.cpp

HEADERS += \
    gift.h \
    giftshop.h \
    mainwindow.h \
    manage.h \
    picbutton.h \
    taskform.h \
    tasksetting.h

FORMS += \
    gift.ui \
    giftshop.ui \
    mainwindow.ui \
    manage.ui \
    taskform.ui \
    tasksetting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
