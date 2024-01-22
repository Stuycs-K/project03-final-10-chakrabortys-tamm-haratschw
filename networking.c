#include "networking.h"

/*Connect to the server
 *return the to_server socket descriptor
 *blocks until connection is made.*/
int client_tcp_handshake(char * server_address) {
    
    struct addrinfo * hints, * results;
    hints = calloc(1, sizeof(struct addrinfo));
    //getaddrinfo
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM; //TCP socket
    int i = getaddrinfo(server_address, PORT, hints, &results);
    err(i, "getaddrinfo error");
    int serverd; //store the socket descriptor here
    //create the socket
    serverd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
    //connect to the server
    i = connect(serverd, results->ai_addr, results->ai_addrlen);
    err(i, "connect error");

    free(hints);
    freeaddrinfo(results);

    return serverd;
}

/*Accept a connection from a client
 *return the to_client socket descriptor
 *blocks until connection is made.
 */
int server_tcp_handshake(int listen_socket){
    int client_socket;
    struct sockaddr_storage client_address;
    socklen_t sock_size;
    sock_size = sizeof(client_address);

    //accept the client connection
    client_socket = accept(listen_socket, (struct sockaddr *) &client_address, &sock_size);

    return client_socket;
}

/*Create and bind a socket.
* Place the socket in a listening state.
*/
int server_setup() {
    //setup structs for getaddrinfo
    struct addrinfo * hints, * results;
    hints = calloc(1, sizeof(struct addrinfo));
    results = calloc(1, sizeof(struct addrinfo));

    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM; //TCP socket
    hints->ai_flags = AI_PASSIVE; //only needed on server
    int i = getaddrinfo(NULL, "1523", hints, &results); //Server sets node to NULL
    err(i, "getaddrinfo error");
    //create the socket
    int clientd;//store the socket descriptor here
    clientd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
	err(clientd, "socket error");
    //this code should get around the address in use error
    int yes = 1;
    if ( setsockopt(clientd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1 ) {
        printf("sockopt  error\n");
        printf("%s\n",strerror(errno));
        exit(-1);
    }
    
    //bind the socket to address and port
    i = bind(clientd, results->ai_addr, results->ai_addrlen);
    err(i, "bind error");
    //set socket to listen state
    listen(clientd, 32);

    //free the structs used by getaddrinfo
    free(hints);
    freeaddrinfo(results);
    
    return clientd;
}

void err(int i, char*message){
    if(i < 0){
	    printf("Error: %s - %s\n",message, strerror(errno));
    	exit(1);
    }
}
