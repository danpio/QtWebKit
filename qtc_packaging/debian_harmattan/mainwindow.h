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
        return QString::fromUtf8("Mozilla/5.0 (iPhone; CPU iPhone OS 5_0 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3 ");
    }
};
class QGraphicsScene;
class WebViewer;
class QGraphicsWebView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:

private:
    Ui::MainWindow *ui;
    MyWebPage *page;
    WebViewer *webview;
    QGraphicsScene *scene;
    QGraphicsWebView *webitem;

};

#endif // MAINWINDOW_H
