#ifndef SERVER_H
#define SERVER_H

#include <sys/select.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>

#define PLAYER_MIN 3
#define PLAYER_LIMIT 32
#define PROMPT_WORD_COUNT 10
#define SKIP_PHRASE "SKIP"

void connect_client(int connections[], int listen_socket);
void disconnect_client(int connections[], int socket_num);

#endif