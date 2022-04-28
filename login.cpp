#include "login.h"
#include "ui_Login.h"


Login::Login(QWidget *parent) :
        QWidget(parent), ui(new Ui::Login) {
    ui->setupUi(this);
    QObject::connect(loginButton, &QPushButton::clicked, this, &buttonPressed);
}

Login::~Login() {
    delete ui;
}

void Login::buttonPressed() {
    //std::cout << "got in buttonPressed" << std:endl;
    //todo process login
}
