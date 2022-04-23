//
// Created by simon on 23.04.22.
//

#ifndef RESTCLIENT_USER_H
#define RESTCLIENT_USER_H
#include <string>

class User {
    long id;
    int pw;
    std::string username;
    std::string name;
    std::string firstName;
    std::string email;
    std::string tel;
    std::string locale;
    long birthday;
    std::byte* profilePicture;
public:
    bool isLoggedIn();
    long getId();
    void setId(long id1);
    int getPw();
    std::string getUsername();
    std::string getName();
    std::string getFirstName();
    std::string getEmail();
    std::string getTel();
    //todo locale in cpp?
    std::string getLocal();
    long getBirthday();
    std::string toString();
    std::byte* getProfilePicture();

    User(std::string name, std::string firstName, std::string email, std::string tel, std::string local, long birthday,
    std::string username, int pw, byte* profilePicture);

    User(std::string name, std::string firstName, std::string email, std::string tel, std::string local, long birthday,
         std::string username, int pw, long id, std::byte* profilePicture);

    char byteToString(std::byte *byte);
};


#endif //RESTCLIENT_USER_H
