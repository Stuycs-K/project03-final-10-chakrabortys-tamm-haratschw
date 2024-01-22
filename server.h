#ifndef SERVER_H
#define SERVER_H

#include <sys/select.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define PLAYER_MIN 3
#define PLAYER_LIMIT 32
#define PROMPT_WORD_COUNT 10
#define SKIP_PHRASE "SKIP"

void connect_client(int connections[], int listen_socket);
void log_entry(int log_file, char name[], char prompt[]);

#endif