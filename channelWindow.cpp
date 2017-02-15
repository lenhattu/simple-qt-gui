#include "channelWindow.h"

ChannelWindow::ChannelWindow(QWidget* parent, vector<QString> src) : QMainWindow(parent)
{
    this->setFixedSize(400, 300);
    this->setWindowTitle("Channel GUI");
    init();
    for (unsigned long i = 0; i < src.size(); i++)
    {
        QAction* input = new QAction(src[i], menuInput);
        input->setCheckable(true);
        QAction* output = new QAction(src[i], menuOutput);
        output->setCheckable(true);
        menuInput->addAction(input);
        menuOutput->addAction(output);
    }
}

ChannelWindow::~ChannelWindow()
{
    delete btnInput;
    delete btnOutput;
    delete btnChannelType;
    delete menuInput;
    delete menuOutput;
    delete menuChannelType;
    delete editChannelName;
    delete btnAdd;
    delete lbChannelName;
    delete lbInput;
    delete lbOutput;
    delete lbChannelType;
}

//init
void ChannelWindow::init()
{
    lbChannelName = new QLabel(this);
    lbInput = new QLabel(this);
    lbOutput = new QLabel(this);
    lbChannelType = new QLabel(this);
    editChannelName = new QLineEdit(this);
    menuInput = new QMenu;
    menuOutput = new QMenu;
    menuChannelType = new QMenu;
    //init channel type menu with actions from 1 to 7
    for (int i = 1; i < 8; i++)
    {
        QString s = QString::number(i);
        QAction* type = new QAction(s, menuChannelType);
        type->setCheckable(true);
        menuChannelType->addAction(type);
    }
    btnInput = new QPushButton("Select inputs...", this);
    btnOutput = new QPushButton("Select outputs...", this);
    btnChannelType = new QPushButton("Select channel types...", this);
    btnAdd = new QPushButton("ADD", this);
    //setup
    setup();
}

//setup UI and events
void ChannelWindow::setup()
{
    //setup channel name label
    lbChannelName->setText("Channel Name:");
    lbChannelName->setGeometry(45, 35, 150, 50);

    //setup channel name text input
    editChannelName->setPlaceholderText("Enter name");
    editChannelName->setGeometry(155, 50, 200, 20);

    //setup input label
    lbInput->setText("Input:");
    lbInput->setGeometry(45, 45, 150, 100);

    //setup output label
    lbOutput->setText("Output:");
    lbOutput->setGeometry(45, 55, 150, 150);

    //show menu events -> rescale width
    connect(menuInput, SIGNAL(aboutToShow()), this, SLOT(resizeMenuInput()));
    connect(menuOutput, SIGNAL(aboutToShow()), this, SLOT(resizeMenuOutput()));
    
    //set menu for dropdown buttons
    btnInput->setMenu(menuInput);
    btnInput->setGeometry(155, 85, 200, 20);
    btnOutput->setMenu(menuOutput);
    btnOutput->setGeometry(155, 120, 200, 20);
    
    //setup channel type label
    lbChannelType->setText("Channel Type:");
    lbChannelType->setGeometry(45, 65, 150, 200);

    //set dropdown list for channel type
    btnChannelType->setMenu(menuChannelType);
    btnChannelType->setGeometry(155, 155, 200, 20);

    //setup 'Add' button
    btnAdd->setGeometry(150, 190, 100, 50);
    connect(btnAdd, &QPushButton::clicked, this, &ChannelWindow::onAdd);
}

//resize the width of the dropdown menu
void ChannelWindow::resizeMenuInput()
{
    menuInput->setMinimumWidth(btnInput->width() - 13);
}

void ChannelWindow::resizeMenuOutput()
{
    menuOutput->setMinimumWidth(btnOutput->width() - 13);
}

//on Add button clicked
void ChannelWindow::onAdd()
{
    //check selected options
    bool checkedInput = false, checkedOutput = false, checkedType = false;
    for (int i = 0; i < menuInput->actions().count(); i++)
    {
        if (menuInput->actions().at(i)->isChecked())
        {
            checkedInput = true;
            listInput.push_back(menuInput->actions().at(i)->text());
        }
        if (menuOutput->actions().at(i)->isChecked())
        {
            checkedOutput = true;
            listOutput.push_back(menuOutput->actions().at(i)->text());
        }
    }
    for (int i = 0; i < menuChannelType->actions().count(); i++)
    {
        if (menuChannelType->actions().at(i)->isChecked())
        {
            checkedType = true;
            listType.push_back(menuChannelType->actions().at(i)->text());
        }
    }
    if (!checkedInput || !checkedOutput || !checkedType)
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
    }
}

//output result to file
void ChannelWindow::output(QString path)
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
    writer << "CHANNEL_TARGETS " << listType.size() << endl;
    writer << "BRANCHTYPE" << endl;
    for (unsigned long i = 1; i <= listType.size(); i++)
    {
        writer << listType[i - 1];
        writer << " " << editChannelName->text();
        writer << " [";
        for (unsigned long j = 0; j < listInput.size(); j++)
        {
            if (j == listInput.size() - 1)
                writer << listInput[j] << "]";
            else
                writer << listInput[j] << ", ";
        }
        writer << " [";
        for (unsigned long k = 0; k < listOutput.size(); k++)
        {
            if (k == listOutput.size() - 1)
                writer << listOutput[k] << "]";
            else
                writer << listOutput[k] << ", ";
        }
        writer << endl;
    }
    //close
    out.close();
    //success msg
    QMessageBox doneMsg;
    doneMsg.information(0, "Saved", "The result has been saved!");
    doneMsg.setFixedSize(500, 200);
}
