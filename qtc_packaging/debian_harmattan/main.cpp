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
static void writeX11OrientationAngleProperty(QWidget* widget, ScreenOrientation orientation = Portrait  )
{

    if (widget) {
        WId id = widget->winId();
        Display *display = QX11Info::display();
        if (!display) return;
        Atom orientationAngleAtom = XInternAtom(display, "_MEEGOTOUCH_ORIENTATION_ANGLE", true);
        XChangeProperty(display, id, orientationAngleAtom, XA_CARDINAL, 32, PropModeReplace, (unsigned char*)&orientation, 0);
    }

}

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    MainWindow w;
    const int width = 854;
    const int height = 480;
    QGraphicsScene scene;

    w.setOrientation(MainWindow::ScreenOrientationAuto);


   // writeX11OrientationAngleProperty(&w,Portrait);
    w.showFullScreen();
    return app.exec();
}
