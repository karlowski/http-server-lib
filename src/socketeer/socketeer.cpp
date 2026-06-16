#include <iostream>
#include <cerrno>
#include <cstring>
#include <stdexcept>
#include <sys/socket.h>
#include <bits/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "socketeer.hpp"

class InternalSocketeerService : public SocketeerService
{
    private:
    public:
    InternalSocketeerService() {}
    ~InternalSocketeerService() {}

    int initializeSocket(int port) override
    {
        sockaddr_in address{
            .sin_family = AF_INET,
            .sin_port = htons(port),
            .sin_addr.s_addr = INADDR_ANY};
        int fd{socket(AF_INET, SOCK_STREAM, 0)};
        int isBound{bind(fd, (sockaddr *)&address, sizeof(address))};

        if (fd < 0 || isBound < 0)
        {
            throw std::runtime_error(
                std::string("Error initiating a socket; ") + std::strerror(errno)
            );
        }

        return fd;
    };

    void listen(unsigned int socket, unsigned int queue) override
    {
        if (::listen(socket, queue) < 0)
        {
            throw std::runtime_error(
                std::string("Error listening to a socket; ") + std::strerror(errno)
            );
        }
    };

    void close(unsigned int socket) override
    {
        ::close(socket);
    };

    int accept(unsigned int socket) override
    {
    };

    void send(unsigned int socket, const char *data, size_t len) override
    {
    };
};
