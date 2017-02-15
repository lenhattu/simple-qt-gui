#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //init labels
    //option
    QLabel* lbOption = new QLabel(this);
    lbOption->setText("Options:");
    lbOption->setGeometry(25, 50, 150, 50);
    //number of branchtypes
    QLabel* lbNumBT = new QLabel(this);
    lbNumBT->setText("Number of branchtypes:");
    lbNumBT->setGeometry(25, 55, 150, 100);
    
    //select options
    //init menu
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
    connect(menuOption, SIGNAL(aboutToShow()), this, SLOT(resizeMenu()));
    //init dropdown button for menu
    btnOption = new QPushButton("Select options...", this);
    btnOption->setMenu(menuOption);
    btnOption->setGeometry(175, 50, 200, 50);

    //init line edit for branchtypes
    QLineEdit* editNumBT = new QLineEdit(this);
    editNumBT->setPlaceholderText("Enter 1 - 7 only");
    editNumBT->setGeometry(183, 95, 100, 20);

    //init 'Generate' button
    btnGenerate = new QPushButton("GENERATE", this);
    btnGenerate->setGeometry(150, 130, 100, 50);
    connect(btnGenerate, &QPushButton::clicked, this, &MainWindow::onGenerate);
}

MainWindow::~MainWindow()
{
}

//resize the width of the dropdown menu
void MainWindow::resizeMenu()
{
    menuOption->setMinimumWidth(btnOption->width() - 13);
}

//validate input from user
bool MainWindow::validate()
{
}

//on Generate button clicked
void MainWindow::onGenerate()
{
}
