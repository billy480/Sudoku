#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <level.h>
using namespace std;
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    level levelnow;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("levelnow", &levelnow);
    engine.loadFromModule("sudoku1", "Main");

    return app.exec();
}
