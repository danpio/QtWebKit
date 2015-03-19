QT += core gui  script
QT += opengl
QT += webkit network
QT += webkitwidgets
QT += core gui
OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog

SOURCES += \
    qtc_packaging/debian_harmattan/main.cpp \
    qtc_packaging/debian_harmattan/mainwindow.cpp \
    qtc_packaging/debian_harmattan/webviewer.cpp

HEADERS += \
    qtc_packaging/debian_harmattan/mainwindow.h \
    qtc_packaging/debian_harmattan/webviewer.h

FORMS += \
    qtc_packaging/debian_harmattan/mainwindow.ui

contains(MEEGO_EDITION,harmattan) {
    target.path = /opt/nienazwany7/bin
    INSTALLS += target
}
