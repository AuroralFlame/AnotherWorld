#include "menuwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QGraphicsItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // TODO：加载动画
    qDebug() << getCurrentTime() << "The Game Is Starting." << endl << "Readying For The Initialization."<<endl;
    QPixmap loadOpen( ":/gamestarted/loading/res/gamestart/test.png" );
    QPixmap set = loadOpen.scaled(800, 800, Qt::KeepAspectRatio);
    QSplashScreen splash(set);
    splash.show();
    a.processEvents();

    MenuWindow w;
    w.show();
    splash.finish(&w);
    qDebug() << getCurrentTime() << "The Initialization Has Finished."<<endl;
    return a.exec();
}
