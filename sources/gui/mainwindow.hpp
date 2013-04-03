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
private:
    Ui::MainWindow *ui;
};
