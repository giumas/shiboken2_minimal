#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtWidgets/QApplication>

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv, bool GUIenabled);
};

#endif // APPLICATION_H
