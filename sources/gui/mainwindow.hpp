#pragma once
#include <QMainWindow>
#include "iface.hpp"

namespace Ui {
class MainWindow;
};

using gui::MainWindowIface;

class MainWindow : public QMainWindow, public MainWindowIface
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    virtual void showWindow();
    virtual void updateWindow(QList<QString> list);
private:
    Ui::MainWindow *ui;

    void on_exitAct_triggered();

private:
    void createMenus();

};
