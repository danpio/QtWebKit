#ifndef WEBVIEWER_H
#define WEBVIEWER_H
#include <QWebPage>
#include <QGraphicsView>




class QGraphicsScene;
class QGraphicsWebView;


class WebViewer : public QGraphicsView
{
    Q_OBJECT

public:
    explicit WebViewer(QWidget *parent = 0);


signals:

public slots:

private:
    QGraphicsScene *scene;
    QGraphicsWebView *webitem;

};

#endif // WEBVIEWER_H
