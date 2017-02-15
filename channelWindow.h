#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QMenu>
#include <QLabel>
#include <QLineEdit>
#include <QtGui>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class ChannelWindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit ChannelWindow(QWidget* parent = 0);
        ~ChannelWindow();
    private:
};
