#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    const QRect availableGeometry =  a.desktop()->availableGeometry(&mainWindow);
    mainWindow.resize(availableGeometry.width() / 2, availableGeometry.height() / 2);
    mainWindow.show();
    return a.exec();
}
