#include <string>
#include <vector>
#include <unordered_map>


enum class HttpMethod 
{
    GET,
    POST,
    PUT,
    PATCH,
    DELETE_,
    HEAD,
    OPTIONS
};

typedef struct {
    std::string path;
    HttpMethod method;
    void* body;
    void* cb;
} RouteHandler;

class RouterBase 
{
    public:
        RouterBase() = default;
        ~RouterBase() = default;

        virtual void addRoutes(std::vector<RouteHandler> routeHandlers) = 0;
        virtual RouteHandler* getRouteHandler(HttpMethod method, std::string path) = 0;
};

class Router : public RouterBase 
{
    private:
        std::unordered_map<HttpMethod, std::unordered_map<std::string, RouteHandler>> routes;
    public:
        Router();
        ~Router();

        void addRoutes(std::vector<RouteHandler> routeHandlers) override;
        RouteHandler* getRouteHandler(HttpMethod method, std::string path) override;
};
