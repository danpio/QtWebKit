#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QX11Info>
#include <X11/Xatom.h>
#include <X11/Xlib.h>


enum ScreenOrientation
{
    Landscape = 0,
    Portrait = 270,
    LandscapeInverted = 180,
    PortraitInverted = 90
};
static void writeX11OrientationAngleProperty(QWidget* widget, ScreenOrientation orientation = Portrait)
{

    if (widget) {
        WId id = widget->winId();
        Display *display = QX11Info::display();
        if (!display) return;
        Atom orientationAngleAtom = XInternAtom(display, "_MEEGOTOUCH_ORIENTATION_ANGLE", false);
        XChangeProperty(display, id, orientationAngleAtom, XA_CARDINAL, 32, PropModeReplace, (unsigned char*)&orientation, 1);
    }

}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    writeX11OrientationAngleProperty(&w);

   w.showFullScreen();
    return a.exec();
}
