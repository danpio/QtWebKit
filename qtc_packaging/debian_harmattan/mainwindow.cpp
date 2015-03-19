#include "mainwindow.h"
#include <QtWebKit>
#include <QtCore/QCoreApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QScriptEngine>
#include "ui_mainwindow.h"
#include "webviewer.h"

QWebSettings *settings;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    page =  new MyWebPage();

    settings = QWebSettings::globalSettings();

    settings->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
    settings->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled,true);
    settings->setAttribute(QWebSettings::LocalContentCanAccessFileUrls,true);
    settings->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
    settings->setAttribute(QWebSettings::JavascriptCanCloseWindows,true);
    settings->setAttribute(QWebSettings::JavascriptEnabled,true);
    settings->setAttribute(QWebSettings::PluginsEnabled,true);



    page->mainFrame()->load(QUrl("http://m.facebook.com"));
  //  page->mainFrame()->load(QUrl("http://playtomax.com/"));
//page->mainFrame()->load(QUrl("http://games-uft.mmi.ru/plants-vs-monsters/?host=playfree-uft.mmi.ru&locale=en&p=playfree-uft.mmi.ru"));
    ui->webView->setPage(page);
}

MainWindow::~MainWindow()
{
    delete ui;
}


