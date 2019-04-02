#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cpp-httplib/httplib.h"

const std::string load_static(const std::string& path) {

    std::ifstream static_file(path.c_str(), std::ios::in);

    std::stringstream stream;

    stream << static_file.rdbuf();
    static_file.close();

    return stream.str();
}

int main(){

    std::cout << "C++ Web API is up!" << std::endl;

    httplib::Server svr;

    const std::string static_html = load_static("./static/index.html");

    svr.Get("/", [&](const httplib::Request& req, httplib::Response& res){
        std::cout << "GET: routes '/'" << std::endl;
        res.set_content(static_html.c_str(), "text/html");
    });

    svr.listen("0.0.0.0", 3000);

    return 0;
}