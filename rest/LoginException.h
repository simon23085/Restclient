//
// Created by simon on 23.04.22.
//

#ifndef RESTCLIENT_LOGINEXCEPTION_H
#define RESTCLIENT_LOGINEXCEPTION_H

#include <exception>

struct LoginException: public std::exception{
    const char * what() const throw(){
        return "Exception while trying to login";
    }
};

#endif //RESTCLIENT_LOGINEXCEPTION_H
