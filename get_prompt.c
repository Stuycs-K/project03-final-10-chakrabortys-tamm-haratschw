#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "scramble_prompt.c"

int main(int argc, char* argv[]){
    char inputBuffer[1000];
    printf("Enter a phrase: ");
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    if(strlen(inputBuffer) > 0 && inputBuffer[strlen(inputBuffer) - 1] == '\n'){
        inputBuffer[strlen(inputBuffer) - 1] = '\0';
    }
    char * result = control_function(inputBuffer);
    printf("Modified Phrase: %s\n", result);
    //free result memory
    free(result);
    return 0;
}