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

    char username[BUFFER_SIZE];
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strlen(username) - 1] = 0;

    int server_socket = client_tcp_handshake(address);
    game_loop(server_socket, username);

    close(server_socket);
    return 0;
}

void game_loop(int server_socket, char * username) {
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);
    char prompt_read[BUFFER_SIZE];
    char prompt_write[BUFFER_SIZE];

    printf("Please wait for your turn.\n");
    read(server_socket, prompt_read, sizeof(prompt_read));
    printf("RING RING RING!\n");
    printf("From the telephone, you hear...\n");
    printf("'%s'\n", prompt_read);
    printf("That doesn't sound quiet right, but you have to pass on the prompt!\n");
    printf("NOTE: type 'SKIP' if you want it to move on to the next person.\n");
    printf("Do your best to fill in the garbled parts of what you heard, and write out the prompt.\n");

    /* Select is used here to add a timeout function */
    struct timeval * timeout = malloc(sizeof(struct timeval));
    timeout->tv_sec = TIMEOUT_SEC;

    int i = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, timeout);

    /* Some error occured */
    if (i == -1) {
        printf("You shouldn't be seeing this...\n");
        strcpy(prompt_write, "SKIP");
    } else if (i == 0) {
        printf("Too slow! Moving on to the next player.\n");
        strcpy(prompt_write, "SKIP");
    } else {
        fgets(prompt_write, sizeof(prompt_write), stdin);
        /* Replace the newline character with a string terminating char */
        prompt_write[strlen(prompt_write) - 1] = 0;
    }

    write(server_socket, prompt_write, sizeof(prompt_write));
}
