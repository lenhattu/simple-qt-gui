#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QComboBox>
#include <QStandardItemModel>
#include <QMenu>
#include <QLabel>
#include <QtGui>

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
    public slots:
        void resizeMenu();
    private:
        QStandardItemModel* model;
        QPushButton *btnOption;
        QMenu *menuOption;
        QLabel *lbOption;
};
