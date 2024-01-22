#include "server.h"
#include "networking.h"
#include "scramble_prompt.c"

int main() {
    char prompt[BUFFER_SIZE] = "";
    char original_prompt[BUFFER_SIZE] = "";
    int connections[PLAYER_LIMIT] = {0};

    int client_socket;
    int listen_socket;

    struct player * current_player = malloc(sizeof(struct player));
    

    listen_socket = server_setup();
    printf("Starting a new telephone session!\n");
    printf("Server now listening on port %s...\n", PORT);
    
    printf("Wait for all 4 players to join before setting the prompt\n>>> ");
    fgets(prompt, sizeof(prompt), stdin);
    prompt[strlen(prompt) - 1] = 0;
    strcpy(original_prompt, prompt);

    for (int connection = 0; connection < PLAYER_MIN; connection++) {
        connections[connection] = server_tcp_handshake(listen_socket);
    }

    /* Looping for each player */
    while (1) {
        for (int connection = 0; connection < PLAYER_MIN; connection++) {
            /* Scramble the prompt here */
            strcpy(prompt, scramble_prompt(prompt));
            char read_prompt[BUFFER_SIZE];
            /* Send the prompt to the user */
            write(connections[connection], prompt, sizeof(prompt));
            /* Read the response from the user*/
            read(connections[connection], read_prompt, sizeof(read_prompt));
            /* If the read prompt is not an empty or skip */
            if (strcmp(read_prompt, "") != 0 && strcmp(read_prompt, " ") != 0 && strcmp(read_prompt, SKIP_PHRASE) != 0) {
                strcpy(prompt, read_prompt);
            }
        }

        /* Game end stuff */
        for (int connection = 0; connection < PLAYER_MIN; connection++) {
            
            close(connections[connection]);
            connections[connection] = 0;
        }
    }

    close(listen_socket);
}


void disconnect_client(int connections[], int socket_num) {
    close(connections[socket_num]);
    connections[socket_num] = 0;
}