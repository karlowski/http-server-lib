#include <stdexcept>

#include "router.hpp"


const std::unordered_map<std::string, HttpMethod> stringToMethodMap
{
    {"GET", HttpMethod::GET},
    {"POST", HttpMethod::POST},
    {"PUT", HttpMethod::PUT},
    {"PATCH", HttpMethod::PATCH},
    {"OPTIONS", HttpMethod::OPTIONS},
    {"HEAD", HttpMethod::HEAD},
    {"DELETE", HttpMethod::DELETE_}
};

const std::unordered_map<HttpMethod, std::string> methodToStringMap
{
    {HttpMethod::GET, "GET" },
    {HttpMethod::POST, "POST"},
    {HttpMethod::PUT, "PUT"},
    {HttpMethod::PATCH, "PATCH"},
    {HttpMethod::OPTIONS, "OPTIONS"},
    {HttpMethod::HEAD, "HEAD"},
    {HttpMethod::DELETE_, "DELETE"}
};

namespace RequestParser 
{
    HttpMethod parseMethod(const std::string& method) 
    {
        try
        {
            return stringToMethodMap.find(method)->second;
        }
        catch(const std::exception& e)
        {
            throw std::runtime_error("Unknown HTTP method: " + method);
        }
    };

    const std::string methodToString(HttpMethod method) 
    {
        {
            return methodToStringMap.find(method)->second;
                // __builtin_unreachable(); // interesting stuff
        }
    };

    // TODO: all the rest
};