#include "client.h"
/* 
    The part of the client that interacts with the user.
    Connections are handled using client_networking.c 
*/

int main() {

}

int network_start(int address) {
    /* Use functions from client_networking.c here */
}

int game_loop() {
    char input[BUFFER_SIZE + 1];

    /* While the game is ongoing */
    while (1) {
        /* If it is the player's turn */
        if (1) {
            /* Give the user the scrambled prompt */
            printf("Your prompt is: PROMPT GOES HERE");
            /* Ask the user to try to write what the original prompt was */
            fgets(input, BUFFER_SIZE, stdin);
            /* Remove newline at the end of the input */
            input[strcspn(input, "\n")] = 0;

            /* Send the input back to the server, give signal of completion*/
        }
        /* Check for a signal to skip your current turn */
    }
}
