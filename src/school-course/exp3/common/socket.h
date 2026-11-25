#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <cstddef>


int connectServer(int port);

int acceptClient(int port);

bool sendAll(int fd, const char *data, size_t size);

bool echoServer(int fd);

bool echoClient(int fd);


#endif
