#include <iostream>
#include <cerrno>
#include <cstring>
#include <stdexcept>
#include <sys/socket.h>
#include <bits/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "socketeer.hpp"

InternalSocketeerService::InternalSocketeerService() {};
InternalSocketeerService::~InternalSocketeerService() {};

int InternalSocketeerService::initializeSocket(int port) 
{
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
    
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

void InternalSocketeerService::listen(unsigned int socket, unsigned int queue) 
{
    if (::listen(socket, queue) < 0) 
    {
        throw std::runtime_error(
            std::string("Error listening to a socket; ") + std::strerror(errno)
        );
    }
};

void InternalSocketeerService::close(unsigned int socket) 
{
    ::close(socket);
};

int InternalSocketeerService::accept(unsigned int socket) 
{
    // TODO
};

void InternalSocketeerService::send(unsigned int socket, const char *data, size_t len) 
{
    // TODO
};
