#include <stdexcept>

#include "router.hpp"


// TODO: unordered_map { HttpMethod, HttpMethodKey(?) } for method parsing

namespace RequestParser {
    HttpMethod parseMethod(const std::string& method) 
    {
        if (method == "GET") return HttpMethod::GET;
        if (method == "POST") return HttpMethod::POST;
        if (method == "PUT") return HttpMethod::PUT;
        if (method == "PATCH") return HttpMethod::PATCH;
        if (method == "OPTIONS") return HttpMethod::OPTIONS;
        if (method == "HEAD") return HttpMethod::HEAD;
        if (method == "DELETE") return HttpMethod::DELETE_;

        throw std::runtime_error("Unknown HTTP method: " + method);
    };

    const std::string methodToString(HttpMethod method) 
    {
        switch (method) 
        {
            case HttpMethod::GET:
                return "GET";
            case HttpMethod::POST:
                return "POST";
            case HttpMethod::PUT:
                return "PUT";
            case HttpMethod::PATCH:
                return "PATCH";
            case HttpMethod::OPTIONS:
                return "OPTIONS";
            case HttpMethod::HEAD:
                return "HEAD";
            case HttpMethod::DELETE_:
                return "DELETE_";
            default:
                __builtin_unreachable(); // interesting stuff
        }
    };

    // TODO: all the rest
};