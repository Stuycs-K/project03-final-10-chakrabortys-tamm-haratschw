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

void parse_args( char* line){
    int status = system(line);
    printf("Scrambling completed\n");
}

int main(){
    char* line;
    size_t buffSize = 0;
    printf("Input prompt here: ");
    getline(&line, &buffSize, stdin);    
    line = strsep(&line, "\n");
    char* args = malloc(sizeof(line) * (strlen(line) + strlen("sentence: ")));
    char* sentence="./sentence \"";
    strcat(args, sentence);
    strcat(args, line);
    strcat(args, "\"");
    parse_args(args);
}