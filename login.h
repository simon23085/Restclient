//
// Created by simon on 28.04.22.
//

#ifndef RESTCLIENT_LOGIN_H
#define RESTCLIENT_LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget {
Q_OBJECT

QPushButton * loginButton;
QLineEdit * passwordInput;
QLineEdit * usernameInput;

public slots:
    void buttonPressed();

public:
    explicit Login(QWidget *parent = nullptr);

    ~Login() override;

private:
    Ui::Login *ui;
};


#endif //RESTCLIENT_LOGIN_H
