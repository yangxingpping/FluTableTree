#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "FluTreeModel.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<FluTreeModel>("FluentUIZ", 1, 0, "FluTreeModel");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
