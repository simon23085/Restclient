//
// Created by simon on 23.04.22.
//

#ifndef RESTCLIENT_MESSAGE_H
#define RESTCLIENT_MESSAGE_H
#include <string>


class Message {
    long id;
    long idr;
    long date;
    std::string text;

public:
    long getId();
    long getIdR();
    long getDate();
    std::string getText();

    Message(long id, long idr, long date, std::string txt);
};


#endif //RESTCLIENT_MESSAGE_H
