#include "router.hpp"


Router::Router() {}
Router::~Router() {}

void Router::addRoutes(std::vector<RouteHandler> routeHandlers) // TODO: make it RouteHandler*
{
    for (const auto& route : routeHandlers) 
    {
        routes[route.method][route.path] = route; 
    }
}

RouteHandler* Router::getRouteHandler(HttpMethod method, std::string path) 
{
    auto methodIterator = routes.find(method);
    if (methodIterator == routes.end()) 
    {
        return nullptr;
    }

    auto pathIterator = methodIterator->second.find(path);
    if (pathIterator == methodIterator->second.end()) 
    {
        return nullptr;
    }

    return &pathIterator->second;
}
