#include "server.h"
#include "networking.h"
#include "scramble_prompt.c"

int main() {
    srand(time(NULL));

    char prompt[BUFFER_SIZE] = "";
    char original_prompt[BUFFER_SIZE] = "";
    int connections[PLAYER_LIMIT] = {0};

    int client_socket;
    int listen_socket;

    char * hostname = "host";
    int log_file = open("latest.log", O_CREAT | O_WRONLY | O_TRUNC, 0611);

    struct player * current_player = malloc(sizeof(struct player));
    

    listen_socket = server_setup();
    printf("Starting a new telephone session!\n");
    printf("Server now listening on port %s...\n", PORT);
    
    printf("Wait for all 3 players to join before setting the prompt\n>>> ");
    fgets(prompt, sizeof(prompt), stdin);
    prompt[strlen(prompt) - 1] = 0;
    strcpy(original_prompt, prompt);

    for (int connection = 0; connection < PLAYER_MIN; connection++) {
        connections[connection] = server_tcp_handshake(listen_socket);
    }

    /* Add the original prompt to the log file */
    log_entry(log_file, hostname, original_prompt);

    /* Looping for each player */
    for (int connection = 0; connection < PLAYER_MIN; connection++) {
        struct player * player_response = malloc(sizeof(struct player));

        /* Scramble the prompt here */
        strcpy(prompt, scramble_prompt(prompt));
        /* Send the prompt to the user, and to the log file */
        write(connections[connection], prompt, sizeof(prompt));
        log_entry(log_file, hostname, prompt);
        /* Read the response from the user*/
        read(connections[connection], player_response, sizeof(struct player));
        log_entry(log_file, player_response->username, player_response->response);
        /* If the read prompt is not an empty or skip */
        // printf("[%s]\n", player_response->response);
        if (strcmp(player_response->response, "") != 0 && strcmp(player_response->response, " ") != 0 && strcmp(player_response->response, SKIP_PHRASE) != 0) {
            strcpy(prompt, player_response->response);
        }
    }

    /* Send the original prompt to all clients, and close the connection */
    for (int connection = 0; connection < PLAYER_MIN; connection++) {
        write(connections[connection], original_prompt, sizeof(original_prompt));
        close(connections[connection]);
        connections[connection] = 0;
    }

    close(listen_socket);
}

void log_entry(int log_file, char name[], char prompt[]) {
    char * COLON = ": ";
    char * NEWLINE = "\n";

    write(log_file, name, strlen(name));
    write(log_file, COLON, strlen(COLON));
    write(log_file, prompt, strlen(prompt));
    write(log_file, NEWLINE, strlen(NEWLINE));
}