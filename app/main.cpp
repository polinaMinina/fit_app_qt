#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    QFile file(":/design/DarkStyle.qss");
    if(file.open(QFile::ReadOnly)) {
        QString stylesheet = file.readAll();
        a.setStyleSheet(stylesheet);
        file.close();
    }
    */


    MainWindow w;
    w.show();


    return a.exec();
}
