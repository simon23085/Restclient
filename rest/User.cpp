//
// Created by simon on 23.04.22.
//

#include "User.h"
#include <cstring>
#include <sstream>

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
//todo use std::to_string instead
/*
std::string User::toString() {
    return          "User{ id=" << id <<
                          ", pw=" << pw <<
                          ", username='" << username + '\''<<
                          ", name='" << name << '\'' <<
                          ", firstName='" << firstName + '\'' <<
                          ", email='" << email + '\'' <<
                          ", tel='" << tel << '\'' <<
                          ", local=" << locale <<
                          ", birthday=" << birthday <<
                          ", profilePicture=" << byteToString(profilePicture) +
                          '}';
}*/
std::ostream& operator<<(std::ostream &strm, User &u){
    return strm << "User{ id=" << u.getId() << ", pw=" << u.getPw() <<
                ", username='" << u.getUsername() + '\''<<
                ", name='" << u.getName() << '\'' <<
                ", firstName='" << u.getFirstName() + '\'' <<
                ", email='" << u.getEmail() + '\'' <<
                ", tel='" << u.getTel() << '\'' <<
                ", local=" << u.getLocal()<<
                ", birthday=" << u.getBirthday() <<
                ", profilePicture=" << u.byteToString(u.getProfilePicture()) <<'}';
}



char User::byteToString(std::byte *b) {
    int n = sizeof(b);
    char chars;
    memcpy(reinterpret_cast<void *>(chars), b, n);// memcpy(chars, b, n);
    return reinterpret_cast<char>(chars);
}
std::byte *User::getProfilePicture() {
    return profilePicture;
}

std::string User::toString() {
    std::ostringstream  myObjectStream;
    myObjectStream << this;
    std::string serializedObj = myObjectStream.str();
    return serializedObj;
}
