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
    bool checkedInput = false, checkedOutput = false;
    for (int i = 0; i < menuInput->actions().count(); i++)
    {
        if (menuInput->actions().at(i)->isChecked())
        {
            checkedInput = true;
        }
        if (menuOutput->actions().at(i)->isChecked())
        {
            checkedOutput = true;
        }
    }
}
