#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "foo_export.h"

class FOO_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    void testFunction1();
};

#endif // MAINWINDOW_H
