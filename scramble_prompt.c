#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* scramble(char* string){
    char* list = calloc(strlen(string), sizeof(list));
    char* modSTR = list;
    int i = 0;
    for(i = 0; i < strlen(string); i++){
        list[i] = *(string + i);
    }
    list[i] = "\0";
    //while(modSTR < start + strlen(string)){}
    printf("Character to be modified: %d or %c\n", *modSTR, *modSTR);
    srand(time(NULL));
    *modSTR = rand() % 94 + 32;
    printf("Character modified into: %d or %c\n", *modSTR, *modSTR);
    printf("%s\n", list);
    return string;
}

int main(){
    char* eggs = scramble("Hello World, Beautiful Day\n");
}