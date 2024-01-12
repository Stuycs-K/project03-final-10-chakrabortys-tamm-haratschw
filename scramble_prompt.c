#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include "linkedlist.c"

struct node {char *word; struct node *nextNode;};

char* scrambleWord(char* string){
    char* list = calloc(strlen(string), sizeof(list));
    char* modSTR = list;
    int i = 0;
    for(i = 0; i < strlen(string); i++){
        list[i] = *(string + i);
    }
    strcpy(&list[i], "\0");
    srand(time(0));
    while(modSTR < list + strlen(string) - 1){
        modSTR += 1;//rand() % (strlen(string) / 3);
        if( (*modSTR < 48) || (*modSTR > 57 && *modSTR < 65) || (*modSTR > 90 && *modSTR < 97) || (*modSTR > 122)){
            continue;//don't replace
        }
        printf("Character to be modified: %d or %c\n", *modSTR, *modSTR);
        *modSTR = rand() % 94 + 33;
        printf("Character modified into: %d or %c\n", *modSTR, *modSTR);
    }
    printf("%s\n", list);
    return string;
}

//separates the prompt into separate words, each to be passed as an argument into scramble().
char* scramble_prompt(char* string){
    char * changer_string = strdup(string);
    char * token, *saveptr;
    //creates linked_list
    struct node *wordList = 0;
    const char* delimiter = " ";
    while((token = strsep(&changer_string, delimiter)) != 0){
        insert_front(wordList, token);
        //this if-statement skips the processing for empty tokens using `continue`.
        if(*token == '\0'){
            continue;
        }
    }
    //loop through completed linked-list
    struct node *traverser = wordList;
    char* word;
    char* updated_word;
    while(traverser != 0){
        strcpy(word, traverser->word);
        strcpy(updated_word, scrambleWord(word));
        strcpy(traverser->word, updated_word);
        traverser = traverser->nextNode;
    }
    print_list(wordList);
    char* return_phrase = "";
    char* spacer = " ";
    *traverser = *wordList;
    while(traverser != 0){
        strcat(return_phrase, traverser->word);
        strcat(return_phrase, spacer);
    }
    free(changer_string);
    return return_phrase;
}

int control_function(char* string){
    char * testing_string = strdup(string);
    int word_counter;
    char * token;
    while(token = strsep(&testing_string, token) != 0){
        if(*token == '\0'){
            continue;
        }
        word_counter++;
    }
}

int main(){
    char* eggs = scramble_prompt("Hello World, Beautiful Day\n");
    printf("%s\n", eggs);
}

//take phrase input
//count number of words in phrase
//create linked list, size = # of words
//pass linkedlist to func -> loops through linked list, calling randomword() func to replace each word in the list
//func passes new linkedlist (or same) to new func
//returns new phrase 