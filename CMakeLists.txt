cmake_minimum_required(VERSION 3.9)
project(Restclient)

find_package(cpprestsdk REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Restclient main.cpp rest/Client.cpp rest/Client.h rest/User.cpp rest/User.h rest/Message.cpp rest/Message.h rest/LoginException.h login.cpp login.h login.ui)
target_link_libraries(Restclient
        Qt::Core
        Qt::Gui
        Qt::Widgets
        cpprestsdk::cpprest
        )