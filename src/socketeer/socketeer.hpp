#include <cstddef>

typedef class SocketeerService
{
    public:
        virtual int initializeSocket(int port) = 0;
        virtual void listen(unsigned int socket, unsigned int queue) = 0;
        virtual void close(unsigned int socket) = 0;
        virtual int accept(unsigned int socket) = 0;
        virtual void send(unsigned int socket, const char *data, size_t len) = 0;
};

class InternalSocketeerService : public SocketeerService
{};
