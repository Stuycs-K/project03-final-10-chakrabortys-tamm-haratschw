#include "client.h"
#include "networking.h"

char input[BUFFER_SIZE];

/* The part of the client that interacts with the user.
   Connections are handled using client_networking.c */

int main(int argc, char *argv[]) {
    char * address = "127.0.0.1";
    if (argc > 1) {
        address = argv[1];
    }
    printf("Welcome to the Telephone game!\nYou are connected to: %s\n\n", address);

    int server_socket = client_tcp_handshake(address);
    game_loop(server_socket);

    return 0;
}


void game_loop(int server_socket) {
    char prompt[BUFFER_SIZE] = "BLAH BLAH BLAH";
    fd_set read_fds;

    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_socket, &read_fds);

        select(server_socket + 1, &read_fds, NULL, NULL, NULL);

        if (FD_ISSET(server_socket, &read_fds)) {
            /* Give the user the scrambled prompt. Let the user wait before their turn comes */
            printf("Seems the lines are slow, please wait for your turn...\n");
            int bytes = read(server_socket, prompt, BUFFER_SIZE);

            if (bytes == 0) {
                close(server_socket);
                printf("Connection to the server terminated!");
            }

            printf("NOTE: You will time out in 30 seconds, write your prompt quickly!\n");
            printf("From your side of the telephone, you heard...\n\"%s\"\n", prompt);
            /* Ask the user to try to write what the original prompt was */
            printf("Pass on what you think the original prompt was.\n>>> ");
            fgets(input, BUFFER_SIZE, stdin);
            /* Remove newline at the end of the input */
            input[strlen(input)] = 0;
            /* Send the input back to the server, */
            int wbytes = write(server_socket, input, BUFFER_SIZE);
            printf("Bytes written: %d", wbytes);
        }
        
    }
}
