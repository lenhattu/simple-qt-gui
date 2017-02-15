#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QComboBox>
#include <QMenu>
#include <QLabel>
#include <QLineEdit>
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
    private slots:
        void onGenerate();
    private:
        QPushButton* btnOption;
        QMenu* menuOption;
        QLineEdit* editNumBT;
        QPushButton* btnGenerate;

        bool validate();
};
