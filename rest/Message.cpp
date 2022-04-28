//
// Created by simon on 23.04.22.
//

#include "Message.h"



long Message::getDate() {
    return date;
}

long Message::getIdR() {
    return idr;
}

long Message::getId() {
    return id;
}

std::string Message::getText() {
    return text;
}

Message::Message(long id1, long idr1, long date1, std::string txt) {
    id = id1;
    idr = idr1;
    date = date1;
    text = txt;
}

std::string Message::toString() {
//todo implement
}


