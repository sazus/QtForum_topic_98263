#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QColor>
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  QObject *rootObject = engine.rootObjects().first();

  /// QML Object List //////////////////////////////////////////////////////////
  QList<QObject*> list = rootObject->findChildren<QObject*>();
  qDebug("list = %d",list.count());
  int i;
  for(i=0;i<list.count();i++)
  {
    QObject *object = list[i];
    qDebug() << "Object" << i << object->objectName();

    /// All find colorBox object change color //////////////////////////////////
    if(object->objectName() == "colorBox")
    {
      QColor color(Qt::yellow);
      object->setProperty("color",color);
      qDebug("Change yellow color");
    }
  }

  /// only 1st find colorBox object change color ///////////////////////////////
  QObject *object = rootObject->findChild<QObject*>("colorBox");
  if(object)
  {
    QColor color(Qt::red);
    object->setProperty("color",color);
    qDebug("Change red color");
  }

  return app.exec();
}
