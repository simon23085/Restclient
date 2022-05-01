#include <QApplication>
#include <QPushButton>
#include "Login.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto login = new Login();
    a.setActiveWindow(login);
    login->show();
    return a.exec();//QApplication::exec();
}
