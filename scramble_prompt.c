#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* scramble(char* string){
    char* modSTR = string;
    //while(modSTR < start + strlen(string)){}
    printf("Character to be modified: %s\n", modSTR + 4);
    *modSTR = 65;//rand() % 94 + 32;
    printf("%s", string);
    return string;
}

int main(){
    char* eggs = scramble("Hello World, Beautiful Day\n");
}