#ifndef SERVER_H
#define SERVER_H

#include <sys/select.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>

#define PLAYER_MIN 4
#define PLAYER_LIMIT 32
#define TIMEOUT_SEC 30
#define PROMPT_WORD_COUNT 10

void connect_client(int connections[], int listen_socket);
void disconnect_client(int connections[], int socket_num);

#endif