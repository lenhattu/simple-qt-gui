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
#include <QFileDialog>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class ChannelWindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit ChannelWindow(QWidget* parent, vector<QString> src);
        ~ChannelWindow();
    public slots:
        void resizeMenuInput();
        void resizeMenuOutput();
    private slots:
        void onAdd();
    private:
        QPushButton* btnInput;
        QPushButton* btnOutput;
        QPushButton* btnChannelType;
        QMenu* menuInput;
        QMenu* menuOutput;
        QMenu* menuChannelType;
        QLineEdit* editChannelName;
        QPushButton* btnAdd;

        QLabel* lbChannelName;
        QLabel* lbInput;
        QLabel* lbOutput;
        QLabel* lbChannelType;

        vector<QString> listInput;
        vector<QString> listOutput;
        vector<QString> listType;

        void init();
        void setup();
        void output(QString path);
};
