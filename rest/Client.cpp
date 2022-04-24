//
// Created by simon on 23.04.22.
//

#include "Client.h"
#include "LoginException.h"
namespace sc = std::chrono;

//get
User Client::currentUser() {
    http_request request(methods::GET);
    setAuth(&request.headers());


    http_client client(url+"/currentUser");

    client.request(request).then([] (http_response response){
        if(response.status_code()==status_codes::OK){
            auto body = response.extract_json().get();
            User user = reinterpret_cast<User &&>(body.as_object());
        }else {
            return nullptr;
        }
    });
}
//post
void Client::sendMessage(Message msg) {
    http_request request(methods::POST);
    request.set_body(msg.toString());

    setAuth(&request.headers());
    http_client client(url+"/sendMessage");
    client.request(request).then([] (http_response response) {
        if(response.status_code()!=status_codes::OK){
            throw "Connection Problem";
        }
    });

}
//post
bool Client::registerUser(User user) {
    http_request request(methods::POST);
    request.set_body(user.toString());
    setAuth(&request.headers());
    http_client client(url+"/register");
    client.request(request).then([] (http_response response) {
        if(response.status_code()==status_codes::OK){
            auto body = response.extract_json().get();
            return body.as_bool();
        }else {
            return false;
        }
    });
}
//post
bool Client::deregister(User user) {
    http_request request(methods::POST);
    request.set_body(user.toString()));
    setAuth(&request.headers());
    http_client client(url+"/deregister");
client.request(request).then([] (http_response response) {
    if(response.status_code()==status_codes::OK){
        auto body = response.extract_json().get();
        return body.as_bool();
    }else {
        return false;
    }
});
}
//get
User Client::search(std::string searchString) {
    http_request request(methods::GET);
    request.set_body(searchString);
    setAuth(&request.headers());


    http_client client(url+"/search");

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
    http_request request(methods::GET);
    //setAuth(&request.headers());
    http_client client(url+"/ping");

    auto time = sc::system_clock::now();
    client.request(request).then([] (http_response response){
        if(response.status_code()==status_codes::OK){
            auto body = response.extract_json().get();
            long val = body.as_integer();
            auto since_epoch = time.time_since_epoch();
            auto millis = sc::duration_cast<sc::milliseconds>(since_epoch);
            long now = millis.count();
            return val-now;
        }else {
            return nullptr;
        }
    });
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
