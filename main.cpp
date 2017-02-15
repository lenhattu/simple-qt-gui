#include <QApplication>
#include <QWidget>
#include "mainWindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow main_window;
    main_window.setFixedSize(400, 200);
    main_window.setWindowTitle("Simple GUI");
    main_window.show();
    return app.exec();
}
