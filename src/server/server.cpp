#include <iostream>
#include <memory>
#include <sys/socket.h>

#include "../../include/http-server.hpp"
#include "../router/router.hpp"


class HttpServer
{
    private:
        std::unique_ptr<SocketeerService> socketeer;
        std::unique_ptr<RouterBase> router;
        HttpServerConfig config;

        HttpServerConfig initConfig(int port)
        {
            this->config = (HttpServerConfig) {
                .fd = 0,
                .port = port,
                .active = 0
            };
        }

    public:
        HttpServer(int port)
            : socketeer(std::make_unique<InternalSocketeerService>())
            , router(std::make_unique<Router>())
        {
            this->initConfig(port);
        }

        explicit HttpServer(int port, std::unique_ptr<SocketeerService> socketInjection)
            : socketeer(std::move(socketInjection))
            , router(std::make_unique<Router>())
        {
            this->initConfig(port);
        }
        ~HttpServer() {};

        
        int run() 
        {
            this->config.fd = this->socketeer->initializeSocket(this->config.port);
            this->config.active = 1;

            while (this->config.active > 1)
            {
                int connection { this->socketeer->accept(this->config.port) };

                // TODO: router / threading
            }
        }
};
