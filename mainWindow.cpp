#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //init labels
    //option
    lbOption = new QLabel(this);
    lbOption->setText("Options:");
    lbOption->setGeometry(100, 50, 100, 50);
    
    menuOption = new QMenu;
    QAction *voltage = new QAction("Voltage", menuOption);
    voltage->setCheckable(true);
    QAction *calcium = new QAction("Calcium", menuOption);
    calcium->setCheckable(true);
    QAction *calciumER = new QAction("CalciumER", menuOption);
    calciumER->setCheckable(true);
    menuOption->addAction(voltage);
    menuOption->addAction(calcium);
    menuOption->addAction(calciumER);

    btnOption = new QPushButton("Select options...", this);
    btnOption->setMenu(menuOption);
    btnOption->setGeometry(200, 50, 200, 50);
    connect(menuOption, SIGNAL(aboutToShow()), this, SLOT(resizeMenu()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::resizeMenu()
{
    menuOption->setMinimumWidth(btnOption->width()-13);
}
