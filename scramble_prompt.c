#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "scramble_prompt.h"

struct node* structHeap(char *word, struct node *nextNode){
    nextNode = calloc(1, sizeof(struct node));
    strcpy(nextNode->word, word);
    return nextNode;
}

//insert word at end of linked list
int wordInserter(struct node *list, char* word){
    struct node *s = structHeap(word, list);
    s->nextNode = list;
    return 0;
}

//frees the linked list of words
struct node * free_list(struct node *list){
    struct node *traverser = list;
    struct node *temp;
    while(traverser != NULL){
        temp = traverser;
        traverser = traverser->nextNode;
        free(temp);
    }
    return NULL;
}

int randomer(char* string){
    size_t string_length = strlen(string);
    int count = 1;
    int rando_num;
    for(int i = 0; i < count; i++){
        //finding rando_num, 0 represents lower index limit.
        rando_num = (rand() % (string_length - 0 + 1)) + 0;
        return rando_num;
    }
    return 0;
}

char* scramble(char* string){
    //initialize time()
    srand(time(0));
    char* list = calloc(strlen(string), sizeof(list));
    char* modSTR = list;
    int i = 0;
    for(i = 0; i < strlen(string); i++){
        list[i] = *(string + i);
    }
    list[i] = "\0";
    //use randomer function
    int random_value = randomer(string);
    printf("\nrandom_value, serves as index position to modify:%s\n", random_value);
    //while(modSTR < start + strlen(string)){}
    printf("Character to be modified: %d or %c\n", *modSTR, *modSTR);
    *modSTR = rand() % 94 + 32;
    printf("Character modified into: %d or %c\n", *modSTR, *modSTR);
    for(int i = 0; i < strlen(string); i++){
        if(i == random_value){
            list[i] = *modSTR;
        }
    }
    printf("%s\n", list);
    return string;
}

//separates the prompt into separate words, each to be passed as an argument into scramble().
char* scramble_prompt(char* string){

    char * old_string = strdup(string);
    char * field;
    const char* delimiters = " ";
    while((field = strsep(&string, delimiters)) != 0){
        if(*field == '\0'){
            continue;
        }

    }
    
}

int main(){
    char* eggs = scramble("Hello World, Beautiful Day\n");
}