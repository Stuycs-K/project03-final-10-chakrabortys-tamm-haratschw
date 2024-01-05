#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* scramble(char* string){
    char* start = calloc(strlen(string), sizeof(string));
    char* modSTR = start;
    //while(modSTR < start + strlen(string)){}
        modSTR += 7;
        *modSTR = 65;//rand() % 94 + 32;
    printf("%s", string);
    return string;
}

int main(){
    scramble("Hello World, Beautiful Day\n");
}