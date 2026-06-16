#include <signal.h>

#ifndef HTTP_SERVER_TYPES_H
#define HTTP_SERVER_TYPES_H

typedef int ServerFd;
typedef volatile sig_atomic_t ServerStatus;
typedef struct {
    ServerFd fd;
    int port;
    ServerStatus active;
} HttpServerConfig;

#endif