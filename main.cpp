#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include <QQmlEngine>
#include "test.h"
int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);



    QQuickView *view = new QQuickView;

    Derived derived(view);

    const QUrl url(QStringLiteral("qrc:/main.qml"));


    view->setSource(url);
    view->show();

    return app.exec();
}
