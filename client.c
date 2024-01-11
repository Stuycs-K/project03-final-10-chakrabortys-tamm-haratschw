#include "client.h"
#include "networking.h"
/* 
    The part of the client that interacts with the user.
    Connections are handled using client_networking.c 
*/

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

    /* While the game is ongoing */
    while (1) {
        /* If it is the player's turn */
        if (1) {
            /* Give the user the scrambled prompt */
            printf("Your prompt is: PROMPT GOES HERE\n");
            /* Ask the user to try to write what the original prompt was */
            printf("Pass on what you think the original prompt was: ");
            fgets(input, BUFFER_SIZE, stdin);
            /* Remove newline at the end of the input */
            input[strcspn(input, "\n")] = 0;
            /* Send the input back to the server, */
            write(server_socket, input, BUFFER_SIZE);
        }
        /* Check for a signal to skip your current turn. Ctrl + C will be used */
    }
}
