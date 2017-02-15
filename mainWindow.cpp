#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    init();
}

MainWindow::~MainWindow()
{
}

//init
void MainWindow::init()
{
    lbOption = new QLabel(this);
    lbNumBT = new QLabel(this);
    menuOption = new QMenu;
    btnOption = new QPushButton("Select options...", this);
    editNumBT = new QLineEdit(this);
    btnGenerate = new QPushButton("GENERATE", this);
    //input
    input();
    //setup
    setup();
}

//load list of options
void MainWindow::input()
{
    //static database for options
    QAction* voltage = new QAction("Voltage", menuOption);
    voltage->setCheckable(true);
    QAction* calcium = new QAction("Calcium", menuOption);
    calcium->setCheckable(true);
    QAction* calciumER = new QAction("CalciumER", menuOption);
    calciumER->setCheckable(true);
    //add to menu
    menuOption->addAction(voltage);
    menuOption->addAction(calcium);
    menuOption->addAction(calciumER);
    /*
    //open file
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox errorMsg;
        errorMsg.critical(0, "Error", "Unable to read input file!");
        errorMsg.setFixedSize(500, 200);
        exit(1);
    }
    //read file
    QTextStream reader(&file);
    QString s;
    while(!reader.atEnd())
    {
        s = reader.readLine();
        QAction* option = new QAction(s, menuOption);
        option->setCheckable(true);
        menuOption->addAction(option);
    }
    file.flush();
    //close file
    file.close();
    */
}

//setup UI and events
void MainWindow::setup()
{
    //setup option label
    lbOption->setText("Options:");
    lbOption->setGeometry(25, 50, 150, 50);

    //number of branchtypes label
    lbNumBT->setText("Number of branchtypes:");
    lbNumBT->setGeometry(25, 55, 150, 100);

    //show menu event -> rescale width of menu
    connect(menuOption, SIGNAL(aboutToShow()), this, SLOT(resizeMenu()));

    //set menu for dropdown button
    btnOption->setMenu(menuOption);
    btnOption->setGeometry(175, 50, 200, 50);

    //setup line edit for branchtypes
    editNumBT->setPlaceholderText("Enter 1 - 7 only");
    editNumBT->setGeometry(183, 95, 100, 20);

    //setup 'Generate' button
    btnGenerate->setGeometry(150, 130, 100, 50);
    connect(btnGenerate, &QPushButton::clicked, this, &MainWindow::onGenerate);
}

//resize the width of the dropdown menu
void MainWindow::resizeMenu()
{
    menuOption->setMinimumWidth(btnOption->width() - 13);
}

//on Generate button clicked
void MainWindow::onGenerate()
{
    //check selected options
    bool checked = false;
    QMenu* newMenu = new QMenu;
    for (int i = 0; i < menuOption->actions().count(); i++)
    {
        if (menuOption->actions().at(i)->isChecked())
        {
            checked = true;
            newMenu->addAction(menuOption->actions().at(i));
        }
    }
    //check number of branchtypes
    bool ok;
    bool accept = false;
    int value = editNumBT->text().toInt(&ok);
    if (ok)
    {
        if (value > 0 && value < 8)
        {
            accept = true;
        }
    }
    if (!checked || !accept)
    {
        QMessageBox errorMsg;
        errorMsg.critical(0, "Error", "Invalid input!");
        errorMsg.setFixedSize(500, 200);
        delete newMenu;
    }
    else
    {
        channelWindow = new ChannelWindow(this);
        channelWindow->show();
    }
}
