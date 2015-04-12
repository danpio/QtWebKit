#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWebPage>
#include <QMainWindow>
 #include <QtGui>
namespace Ui {
    class MainWindow;
}



class MyWebPage : public QWebPage
{
    Q_OBJECT
protected:

    virtual QString userAgentForUrl(const QUrl &url) const
    {

        //return QString::fromUtf8("Mozilla/5.0 (iPhone; CPU iPhone OS 5_0 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3 ");
        return QString::fromUtf8("Mozilla/5.0 (X11; U; Linux i686; pl-PL; rv:1.7.10) Gecko/20050717 Firefox/6.0.");
        //return QString::fromUtf8("Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_2) AppleWebKit/600.4.10 (KHTML, like Gecko) Version/8.0.4 Safari/600.4.10");
    }
};
class QGraphicsScene;
class WebViewer;
class QGraphicsWebView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

void setOrientation(ScreenOrientation orientation);

private slots:

private:
    Ui::MainWindow *ui;
    MyWebPage *page;
    WebViewer *webview;
    QGraphicsScene *scene;
    QGraphicsWebView *webitem;

};

#endif // MAINWINDOW_H
