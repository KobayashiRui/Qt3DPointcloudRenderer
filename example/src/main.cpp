#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <qqml.h>
#include <QDebug>
#include "qpointcloud.h"
#include "qpointcloudgeometry.h"
#include "qpointfield.h"
#include "qpointcloudreader.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
        QQuickView view;
    QSurfaceFormat format;

    qmlRegisterType<QPointCloudReader>("pcl", 1, 0, "PointcloudReader");
    qmlRegisterType<QPointcloud>("pcl", 1, 0, "Pointcloud");
    qmlRegisterType<QPointcloudGeometry>("pcl", 1, 0, "PointcloudGeometry");
    qmlRegisterUncreatableType<QPointfield>("pcl", 1, 0, "Pointfield", "Can not yet be created in qml, use PointcloudReader.");
    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:///qml/main.qml")));


    format.setVersion(3,3);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);

    view.setFormat(format);

    view.resize(800, 800);
    view.setResizeMode(QQuickView::SizeRootObjectToView);


    view.setSource(QUrl("qrc:/qml/main.qml"));
    view.show();
;

    int result = app.exec();
    return result;
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR argv, int argc)
{
//    int argc=1;
//    char *argv[] = {"temp"};
    return main(argc, &argv);
}
#endif
