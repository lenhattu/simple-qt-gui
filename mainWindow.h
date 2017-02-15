#include "channelWindow.h"

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
        ChannelWindow* channelWindow;

        QLabel* lbOption;
        QLabel* lbNumBT;

        void init();
        void input();
        void setup();
};
