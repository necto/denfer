#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showWindow()
{
    show();
}

namespace gui
{

MainWindowIface* MainWindowIface::create( int argc, char** argv)
{
    (void)argc;
    (void)argv;
    return new MainWindow( );
}

bool MainWindowIface::destroy( MainWindowIface* ref)
{
    delete (MainWindow*)ref;
    return true;
}

} //namespace gui
