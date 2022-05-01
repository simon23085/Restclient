#include <iostream>
#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::Login) {
    ui->setupUi(this);
    usernameInput = ui->usernameInput;
    passwordInput = ui->passwordInput;
    loginButton = ui->loginButton;

    QObject::connect(ui->loginButton, &QPushButton::clicked, this, &Login::buttonPressed);
    //this ->setCentralWidget(new QWidget(this));
    std::cout<<"constructor done"<<std::endl;
}

Login::~Login() {
    delete ui;
}

void Login::buttonPressed() {
    //todo process login
    std::cout << "got here" <<std::endl;
}
