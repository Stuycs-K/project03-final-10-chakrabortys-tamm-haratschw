#include "server.h"
#include "networking.h"

int main() {
    char prompt[BUFFER_SIZE + 1];
    int cleint_socket;
    int listen_socket;
    fd_set read_fds;

    listen_socket = server_setup();
    
    while(1) {
        FD_ZERO(&read_fds);
        FD_SET(listen_socket, &read_fds);
        int i = select(listen_socket+1, &read_fds, NULL, NULL, NULL);

        socklen_t sock_size;
        struct sockaddr_storage client_address;
        sock_size = sizeof(client_address);

        // if socket
        if (FD_ISSET(listen_socket, &read_fds)) {
            //accept the connection
            int client_socket = accept(listen_socket,(struct sockaddr *)&client_address, &sock_size);
            printf("Connected, waiting for data.\n");

            //read the whole prompt
            read(client_socket,prompt, sizeof(prompt));
            //trim the string
            prompt[strlen(prompt)-1]=0; //clear newline
            if(prompt[strlen(prompt)-1]==13){
                //clear windows line ending
                prompt[strlen(prompt)-1]=0;
            }

            printf("\nRecieved from client '%s'\n",prompt);
            close(client_socket);
        }
    }
}
