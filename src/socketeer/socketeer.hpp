#include <cstddef>

class SocketeerService 
{
    public:
        virtual int initializeSocket(int port) = 0;
        virtual void listen(unsigned int socket, unsigned int queue) = 0;
        virtual void close(unsigned int socket) = 0;
        virtual int accept(unsigned int socket) = 0;
        virtual void send(unsigned int socket, const char *data, size_t len) = 0;
};

class InternalSocketeerService : public SocketeerService 
{
    private:
    public:
    InternalSocketeerService();
    ~InternalSocketeerService();

    int initializeSocket(int port) override;
    void listen(unsigned int socket, unsigned int queue) override;
    void close(unsigned int socket) override;
    int accept(unsigned int socket) override;
    void send(unsigned int socket, const char *data, size_t len) override;
};