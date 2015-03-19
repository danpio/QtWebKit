#include <QGraphicsScene>
#include <QtWebKit/QGraphicsWebView>
#include "webviewer.h"

WebViewer::WebViewer(QWidget *parent) :
    QGraphicsView(parent)
{
/*
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0,854,480);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    setResizeAnchor(AnchorViewCenter);

    QWebSettings *settings = QWebSettings::globalSettings();
   settings->setAttribute(QWebSettings::PluginsEnabled, true);


    webitem = new QGraphicsWebView();
    scene->addItem(webitem);


    // Orientation fixed to portrait in this example
    webitem->setGeometry(QRectF(0, 0,854, 480 ));
    webitem->setRotation(270);
    webitem->setPos(QPointF(0, 480));
    //a = new cos();


   // webitem->page()->userAgentForUrl(QUrl("Mozilla/5.0 (iPhone; CPU iPhone OS 5_0 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3 "));




    webitem->load(QUrl("http://www.wab.com/?screen=264"));

*/
}
