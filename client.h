#ifndef CLIENT_H
#define CLIENT_H

#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void game_loop(int server_socket);

#endif