//
// Created by simon on 23.04.22.
//

#include "Client.h"
#include "LoginException.h"

//get
User Client::currentUser() {
    return nullptr;
}
//post
void Client::sendMessage(Message msg) {

}
//post
bool Client::registerUser(User user) {
    return nullptr;
}
//post
bool Client::deregister(User user) {
    return nullptr;
}
//get
User Client::search(std::string searchString) {
    http_request request(methods::GET);
    setAuth(&request.headers());


    http_client client(url+"/login");

    client.request(request).then([] (http_response response){
        if(response.status_code()==status_codes::OK){
            auto body = response.extract_json().get();
            User user = reinterpret_cast<User &&>(body.as_object());
        }else {
            return nullptr;
        }
    });
}
//get
long Client::ping() {
    return 0;
}
//post
void Client::storeMessage(std::vector<Message> msgs) {

}

void Client::setAuth(http_headers* headers) {
    headers->add("username", username);
    headers->add("password", pw);
}

void Client::login(std::string username, std::string pw) {
    //store for future use
    this->username=username;
    this->pw = std::hash<std::string>()(pw);
    //test auth
    http_request request(methods::GET);
    //request._set_base_uri(url);
    setAuth(&request.headers());
    http_client client(url+"/login");

    client.request(request).then([] (http_response response){
        if(response.status_code()==status_codes::OK){
            auto body = response.extract_string().get();//or json?
            std::cout<<body<<std::endl;
        }else {
            throw new LoginException;
        }
    });
}
