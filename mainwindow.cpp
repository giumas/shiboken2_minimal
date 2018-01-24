#include "mainwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>

#include <QtGui/QIcon>

#include <QtCore/QDebug>
#include <QtCore/QTextStream>

static const char defaultScript[] =
    "print(\"Hello, world\")\n"
    "mainWindow.testFunction1()\n";

MainWindow::MainWindow()
{
    setWindowTitle(tr("Scriptable Application"));

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    const QIcon quitIcon = QIcon::fromTheme(QStringLiteral("application-exit"));
    QAction *quitAction = fileMenu->addAction(quitIcon, tr("&Quit"), qApp, &QCoreApplication::quit);
    quitAction->setShortcut(Qt::CTRL + Qt::Key_Q);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    const QIcon aboutIcon = QIcon::fromTheme(QStringLiteral("help-about"));
    QAction *aboutAction = helpMenu->addAction(aboutIcon, tr("&About Qt"), qApp, &QApplication::aboutQt);

    QToolBar *toolBar = new QToolBar;
    addToolBar(toolBar);
    toolBar->addAction(quitAction);
    toolBar->addSeparator();
    toolBar->addAction(aboutAction);
}

void MainWindow::testFunction1()
{
    static int n = 1;
    QString message;
    QTextStream(&message) << __FUNCTION__ << " called #" << n++;
    qDebug().noquote() << message;
    statusBar()->showMessage(message);
}
