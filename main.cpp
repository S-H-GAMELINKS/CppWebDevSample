#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <vector>
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

    const std::array<std::string, 4> routes = { "/", "/about", "/contact", "/chats" };

    const std::string static_html = load_static("./static/index.html");

    const std::string static_javascript = load_static("./static/index.js");

    std::vector<std::string> talks;

    for(auto&& r : routes)
        svr.Get(r.c_str(), [&](const httplib::Request& req, httplib::Response& res){
            std::cout << "GET: routes " << r << std::endl;
            res.set_content(static_html.c_str(), "text/html");
        });

    svr.Get("/index.js", [&](const httplib::Request& req, httplib::Response& res){
        std::cout << "GET: routes '/index.js'" << std::endl;
        res.set_content(static_javascript.c_str(), "text/javascript");
    });

    svr.Get("/api/talks", [&](const httplib::Request& req, httplib::Response& res) {
        std::ostringstream content;

        for(auto&& t: talks)
            content << "<p>" << t.c_str() << "</p>";

        res.set_content(content.str(), "text/plain");
    });

    svr.Post("/api/talks", [&](const httplib::Request& req, httplib::Response& res) {
        try {
            talks.emplace_back(std::move(req.body));
            std::cout << "Create Talks!" << std::endl;
            res.set_content("Create Talks!", "text/plain");
        } catch(...) {
            std::cout << "Can not Create Talks!" << std::endl;
            res.set_content("Can not Create Talks!", "text/plain");
        }
    });

    svr.listen("0.0.0.0", 3000);

    return 0;
}