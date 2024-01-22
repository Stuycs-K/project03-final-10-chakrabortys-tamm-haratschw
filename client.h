#ifndef CLIENT_H
#define CLIENT_H

#include <sys/select.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define TIMEOUT_SEC 30

void game_loop(int server_socket, char * username);

#endif