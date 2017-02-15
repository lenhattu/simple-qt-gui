#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(400, 200);
    this->setWindowTitle("Simple GUI");
    init();
}

MainWindow::~MainWindow()
{
    delete btnOption;
    delete menuOption;
    delete editNumBT;
    delete btnGenerate;
    delete channelWindow;
    delete lbOption;
    delete lbNumBT;
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
    lbOption->setGeometry(25, 50, 150, 40);

    //number of branchtypes label
    lbNumBT->setText("Number of branchtypes:");
    lbNumBT->setGeometry(25, 55, 150, 100);

    //show menu event -> rescale width of menu
    connect(menuOption, SIGNAL(aboutToShow()), this, SLOT(resizeMenu()));

    //set menu for dropdown button
    btnOption->setMenu(menuOption);
    btnOption->setGeometry(175, 50, 200, 40);

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
    for (int i = 0; i < menuOption->actions().count(); i++)
    {
        if (menuOption->actions().at(i)->isChecked())
        {
            checked = true;
            list.push_back(menuOption->actions().at(i)->text());
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
    }
    else
    {
        //trigger save file dialog to let user choose where to save result
        QString path = QFileDialog::getSaveFileName(this, tr("Save Result"), "", "Parchive File (*.par)");
        if (path != NULL) //is NULL when user clicks cancel
            this->output(path);
        //go to Channel window
        channelWindow = new ChannelWindow(this, list);
        channelWindow->setWindowModality(Qt::ApplicationModal);
        channelWindow->show();
    }
    //refresh the list
    list.clear();
}

//output result to file
void MainWindow::output(QString path)
{
    //open file
    QFile out(path);
    if (!out.open(QIODevice::WriteOnly))
    {
        QMessageBox errorMsg;
        errorMsg.critical(0, "Error", "Unable to open file to write!");
        errorMsg.setFixedSize(500, 200);
        return;
    }
    QTextStream writer(&out);
    //write
    int count = this->editNumBT->text().toInt();
    writer << "COMPARTMENT_VARIABLE_TARGETS " << count << endl;
    writer << "BRANCHTYPE" << endl;
    for (int i = 1; i <= count; i++)
    {
        writer << i;
        for (unsigned long j = 0; j < list.size(); j++)
            writer << " " << list[j];
        writer << endl;
    }
    //close
    out.close();
    //success msg
    QMessageBox doneMsg;
    doneMsg.information(0, "Saved", "The result has been saved!");
    doneMsg.setFixedSize(500, 200);
}
