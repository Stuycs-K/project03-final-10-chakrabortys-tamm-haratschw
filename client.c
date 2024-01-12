#include "client.h"
#include "networking.h"

/* The part of the client that interacts with the user.
   Connections are handled using client_networking.c */

int main() {
    int server_socket = network_start("127.0.0.1");
    game_loop(server_socket);
    close(server_socket);
}

int network_start(char * address) {
    int server_socket = client_tcp_handshake(address);
    /* Perform some other networking actions as well. */
    return server_socket;
}

void game_loop(int server_socket) {
    char input[BUFFER_SIZE];

    /* Check for a signal to skip your current turn. Ctrl + C will be used */
    signal(SIGINT, sighandler);
    /* Give the user the scrambled prompt */
    printf("NOTE: Use CTRL+C to skip your turn!\n");
    printf("From your side of the telephone, you heard...\nPROMPT GOES HERE\n");
    /* Ask the user to try to write what the original prompt was */
    printf("Pass on what you think the original prompt was.\n>>> ");
    fgets(input, BUFFER_SIZE, stdin);
    /* Remove newline at the end of the input */
    input[strlen(input)] = 0;
    /* Send the input back to the server, */
    write(server_socket, input, BUFFER_SIZE);
}

static void sighandler(int signo) {
    if (signo == SIGINT) {
        /* Tell the server to skip the turn, somehow. 
           Possible implementation: use a static variable, then change its value.
           Make sure to let select in server.c unblock after a period of time.
           Maybe a time out function might be better. */
    }
}