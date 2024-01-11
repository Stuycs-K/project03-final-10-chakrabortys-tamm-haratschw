#include "server.h"
#include "client_networking.h"

int main() {
    char prompt[BUFFER_SIZE];
    int listen_socket = server_setup();
    int client_socket = server_tcp_handshake(listen_socket);


}