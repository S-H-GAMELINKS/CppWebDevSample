#include <iostream>
#include "cpp-httplib/httplib.h"

int main(){

    std::cout << "C++ Web API is up!" << std::endl;

    httplib::Server svr;

    svr.Get("/", [](const httplib::Request& req, httplib::Response& res){
        std::cout << "GET: routes '/'" << std::endl;
        res.set_content("Hi! Welcome to C++ Web App!", "text/plain");
    });

    svr.listen("0.0.0.0", 3000);

    return 0;
}