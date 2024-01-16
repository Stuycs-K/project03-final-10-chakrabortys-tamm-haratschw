#include "server.h"
#include "networking.h"
#include "scramble_prompt.c"
#include "random_prompt.c"

int main() {
    char prompt[BUFFER_SIZE] = "";
    int connections[PLAYER_LIMIT];

    for (int socket = 0; socket < PLAYER_LIMIT; socket++) {
        connections[socket] = 0;
    }

    int client_socket;
    int listen_socket;
    int max_socket;
    fd_set read_fds;
    
    struct timeval * timeout = malloc(sizeof(struct timeval)); 
    timeout->tv_sec = TIMEOUT_SEC;

    listen_socket = server_setup();
    printf("Telephone game server is now listening...\n");
    
    /* Setup prompt for players */
    strcpy(prompt, randomPrompt(PROMPT_WORD_COUNT));
    printf("The randomly selected prompt is: %s\n", prompt);

    while(1) {
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
        FD_SET(listen_socket, &read_fds);
        
        /* This will be updated as more sockets are added to the list, but starts at the listen one */
        max_socket = listen_socket;
        /* Handle client connections to the server, and add them to read_fds */
        for (int player = 0; player < PLAYER_LIMIT; player++) {
            /* If the connection chosen is an used socket */
            if (connections[player] > 0) {
                FD_SET(connections[player], &read_fds);
            }
            /* Update the max socket with the newest one added */
            if (connections[player] > max_socket) {
                max_socket = connections[player];
            }
        }

        int i = select(max_socket + 1, &read_fds, NULL, NULL, NULL);
        err(i, "error selecting");

        if (FD_ISSET(listen_socket, &read_fds)) {
            // connect_client(connections, listen_socket);
            int client_socket = server_tcp_handshake(listen_socket);
            printf("A client connection has been established!\n");

            /* Check for an open socket slot, then add the newest connection */
            for (int connection = 0; connection < PLAYER_LIMIT; connection++) {
                if (connections[connection] == 0) {
                    connections[connection] = client_socket;
                }
                break;
    }
        }
        /* Go through each socket one at a time. For each connection,
        give it the prompt (or the modified version so far), wait
        for an input, then read the prompt and scramble it, setting
        it as the new prompt for the next user. */
        for (int player = 0; player < PLAYER_LIMIT; player++) {

            if (FD_ISSET(connections[player], &read_fds)) {
                /* Send the player the prompt so far */
                write(connections[player], prompt, BUFFER_SIZE);
                /* Read the new prompt from the player */
                char read_prompt[BUFFER_SIZE];
                int bytes = read(connections[player], read_prompt, BUFFER_SIZE);
                if (bytes != 0) {
                    /* ADD CODE HERE TO SCRAMBLE THE PROMPT */
                    strncpy(prompt, read_prompt, BUFFER_SIZE);
                    printf("The new prompt, scrambled, is: %s\n", prompt);
                } else {
                    close (connections[player]);
                    connections[player] = 0;
                }
            }
        }
    }

    close(listen_socket);
}

void connect_client(int connections[], int listen_socket) {
    int client_socket = server_tcp_handshake(listen_socket);
    printf("A client connection has been established!\n");

    /* Check for an open socket slot, then add the newest connection */
    for (int connection = 0; connection < PLAYER_LIMIT; connection++) {
        if (connections[connection] == 0) {
            connections[connection] = client_socket;
        }
        break;
    }
}

void disconnect_client(int connections[], int socket_num) {
    close(connections[socket_num]);
}