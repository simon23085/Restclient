//
// Created by simon on 23.04.22.
//

#include "User.h"

User::User(std::string name, std::string firstName, std::string email, std::string tel, std::string local,
           long birthday, std::string username, int pw, std::byte *profilePicture) {
    this->name = name;
    this->firstName = firstName;
    this->email = email;
    this->tel = tel;
    this->locale = local;
    this->birthday = birthday;
    this->username = username;
    this->pw = pw;
    this->profilePicture = profilePicture;

}

bool User::isLoggedIn() {
    return id!=0;
}

long User::getId() {
    return id;
}

void User::setId(long id1) {
    id=id1;
}

int User::getPw() {
    return pw;
}

std::string User::getUsername() {
    return username;
}

std::string User::getName() {
    return name;
}

std::string User::getFirstName() {
    return firstName;
}

std::string User::getEmail() {
    return email;
}

std::string User::getTel() {
    return tel;
}

std::string User::getLocal() {
    return locale;
}

long User::getBirthday() {
    return birthday;
}

User::User(std::string name, std::string firstName, std::string email, std::string tel, std::string local,
           long birthday, std::string username, int pw, long id, std::byte *profilePicture) {
    this->name = name;
    this->firstName = firstName;
    this->email = email;
    this->tel = tel;
    this->locale = local;
    this->birthday = birthday;
    this->username = username;
    this->pw = pw;
    this->profilePicture = profilePicture;
    this->id = id;

}

std::string User::toString() {
    return          "User{" +
                          "id=" + id +
                          ", pw=" + pw +
                          ", username='" + username + '\'' +
                          ", name='" + name + '\'' +
                          ", firstName='" + firstName + '\'' +
                          ", email='" + email + '\'' +
                          ", tel='" + tel + '\'' +
                          ", local=" + local +
                          ", birthday=" + birthday +
                          ", profilePicture=" + byteToString(profilePicture) +
                          '}';
}

std::byte *User::getProfilePicture() {
    return profilePicture;
}

char User::byteToString(std::byte *b) {
    int n = sizeof(b);
    char chars;
    memcpy(chars, b, n);
    return reinterpret_cast<char>(chars);
}
