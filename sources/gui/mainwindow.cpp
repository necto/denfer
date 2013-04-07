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

void MainWindow::updateWindow(QList<QString> list)
{
    this->ui->Processes->clear();
    QStringList* qlist = new QStringList(list);
    this->ui->Processes->addItems(*qlist);
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
