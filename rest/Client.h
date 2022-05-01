//
// Created by simon on 23.04.22.
//

#ifndef RESTCLIENT_CLIENT_H
#define RESTCLIENT_CLIENT_H
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include "User.h"
#include "Message.h"

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

class Client {
    long id;
    std::string url;
    int port;
    int pw;
    std::string username;
    std::vector<Message> messages;
private:
    Client() {}
    //idk whats this
    //Client(Client const&); //don't implement
    //void operator=(Client const&);//don't implement

public:
    User* currentUser();
    void sendMessage(Message msg);
    bool registerUser(User user);
    bool deregister(User user);
    User* search(std::string searchString);
    long ping();
    void storeMessage(std::vector<Message> msgs);
    int getMessage();

    static Client& getInstance(){
        static Client instance;
        return instance;
    }
    Client(Client const&)               = delete;
    void operator=(Client const&)  = delete;

    //background
    void startBackground();
    //todo change to stream
    std::vector<Message> getMessages();

    //todo complete
    void storeKey();
    void getKeys();

    //utility
    void setAuth(http_headers *headers);
    void login(std::string username, std::string pw);
};


#endif //RESTCLIENT_CLIENT_H
