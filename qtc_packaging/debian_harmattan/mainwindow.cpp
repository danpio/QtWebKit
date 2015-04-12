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
QNetworkDiskCache* m_cache;
QNetworkAccessManager* m_network;

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    m_network = new QNetworkAccessManager(this);
    m_cache = new QNetworkDiskCache(this);
    m_cache->setCacheDirectory(QDesktopServices::storageLocation(QDesktopServices::CacheLocation) + "/imageanalyzer");
    m_cache->setMaximumCacheSize(1000000); //set the cache to 10megs
    m_network->setCache(m_cache);



    ui->setupUi(this);
    ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    page =  new MyWebPage();
QString cacheDirPath;

    cacheDirPath=QString::number(qrand());

    settings = QWebSettings::globalSettings();

    ui->webView->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
    ui->webView->settings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled,true);
    ui->webView->settings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls,true);
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptCanCloseWindows,true);
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled,true);

ui->webView->settings()->enablePersistentStorage(QDir::currentPath()+"/cache/"+cacheDirPath);
ui->webView->settings()->setLocalStoragePath(QDir::currentPath()+"/cache/"+cacheDirPath);
ui->webView->settings()->setOfflineStoragePath(QDir::currentPath()+"/cache/"+cacheDirPath);
ui->webView->settings()->setIconDatabasePath(QDir::currentPath()+"/cache/"+cacheDirPath);
ui->webView->settings()->setOfflineWebApplicationCachePath(QDir::currentPath()+"/cache/"+cacheDirPath);

ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
//QWebSettings::globalSettings()->setAttribute(QWebSettings::TiledBackingStoreEnabled, true);

QWebSettings::globalSettings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
QWebSettings::globalSettings()->setAttribute(QWebSettings::FrameFlatteningEnabled, true);

QWebSettings::globalSettings()->setOfflineStoragePath("./home/user/");
page->settings()->setUserStyleSheetUrl(QUrl::fromLocalFile("mycss.css"));
page->mainFrame()->load(QUrl("https://messenger.com/login/"));

//    page->mainFrame()->load(QUrl("http://m.facebook.com"));
//    page->mainFrame()->load(QUrl("http://playtomax.com/"));
//    page->mainFrame()->load(QUrl("https://mobile.twitter.com"));
//page->mainFrame()->load(QUrl("http://games-uft.mmi.ru/plants-vs-monsters/?host=playfree-uft.mmi.ru&locale=en&p=playfree-uft.mmi.ru"));


    ui->webView->setPage(page);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOrientation(ScreenOrientation orientation)
{


    // If the version of Qt on the device is < 4.7.2, that attribute won't work
    if (orientation != ScreenOrientationAuto) {
        const QStringList v = QString::fromAscii(qVersion()).split(QLatin1Char('.'));
        if (v.count() == 3 && (v.at(0).toInt() << 16 | v.at(1).toInt() << 8 | v.at(2).toInt()) < 0x040702) {
            qWarning("Screen orientation locking only supported with Qt 4.7.2 and above");
            return;
        }
    }

    Qt::WidgetAttribute attribute;
    switch (orientation) {
#if QT_VERSION < 0x040702
    // Qt < 4.7.2 does not yet have the Qt::WA_*Orientation attributes
    case ScreenOrientationLockPortrait:
        attribute = static_cast<Qt::WidgetAttribute>(128);
        break;
    case ScreenOrientationLockLandscape:
        attribute = static_cast<Qt::WidgetAttribute>(129);
        break;
    default:
    case ScreenOrientationAuto:
        attribute = static_cast<Qt::WidgetAttribute>(130);
        break;
#else // QT_VERSION < 0x040702
    case ScreenOrientationLockPortrait:
        attribute = Qt::WA_LockPortraitOrientation;
        break;
    case ScreenOrientationLockLandscape:
        attribute = Qt::WA_LockLandscapeOrientation;
        break;
    default:
    case ScreenOrientationAuto:
        attribute = Qt::WA_AutoOrientation;
        break;
#endif // QT_VERSION < 0x040702
    };
    setAttribute(attribute, true);
}
