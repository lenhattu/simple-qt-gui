#include "channelWindow.h"

ChannelWindow::ChannelWindow(QWidget* parent) : QMainWindow(parent)
{
    this->setFixedSize(400, 200);
    this->setWindowTitle("Channel GUI");
}

ChannelWindow::~ChannelWindow()
{
}
