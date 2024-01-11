#ifndef CLIENT_NETWORKING_H
#define CLIENT_NETWORKING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h> 
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT "15236"

int client_tcp_handshake(char*server_address);
int server_tcp_handshake(int listen_socket);
int server_setup();
void err(int i, char*message);

#endif