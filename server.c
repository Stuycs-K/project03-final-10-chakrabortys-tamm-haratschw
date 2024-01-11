#include "server.h"
#include "networking.h"

int main() {
    char prompt[BUFFER_SIZE];
    int listen_socket;
    fd_set read_fds;

    FD_ZERO(&read_fds);
    listen_socket = server_setup();
    while (1) connection_handle(listen_socket);
    // read(client_socket, prompt, BUFFER_SIZE);
    // printf("%s\n", prompt);

    // close(client_socket);
}

void connection_handle(int listen_socket) {
    for (int connection = 0; connection < PLAYER_LIMIT; connection++) {

    }
}