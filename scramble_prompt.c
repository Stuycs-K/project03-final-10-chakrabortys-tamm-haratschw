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

int printList(struct node *head){
    struct node *temp = head;
    while(temp != 0){
        printf("%s\n", temp->word);
        temp = temp->nextNode;
    }
    return 0;
}

//frees the linked list of words
struct node * free_list(struct node *list){
    struct node *traverser = list;
    struct node *temp;
    while(traverser != 0){
        temp = traverser;
        traverser = traverser->nextNode;
        free(temp);
    }
    return 0;
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

char* scrambleWord(char* string){
    /*
    //initialize time()
    srand(time(0));
    char* list = calloc(strlen(string), sizeof(list));
    char* modSTR = list;
    int i;
    for(i = 0; i < strlen(string); i++){
        list[i] = *(string + i);
    }
    strcpy(&list[i], "\0");
    //use randomer function
    int random_value = randomer(string);
    /*
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
    */
    //work on modSTR
    /*
    while(modSTR < list + strlen(string) - 1){
        modSTR += 1;//rand() % (strlen(string) / 3);
        if( (*modSTR < 48) || (*modSTR > 57 && *modSTR < 65) || (*modSTR > 90 && *modSTR < 97) || (*modSTR > 122)){
            continue;//don't replace
        }
        if(modSTR == random_value){
            printf("Character to be modified: %d or %c\n", *modSTR, *modSTR);
            *modSTR = rand() % 94 + 33;
            printf("Character modified into: %d or %c\n", *modSTR, *modSTR);
        }
    }
    printf("%s\n", list);
    return string;
    */
    char* list = calloc(strlen(string), sizeof(list));
    char* modSTR = list;
    int i = 0;
    for(i = 0; i < strlen(string); i++){
        list[i] = *(string + i);
    }
    list[i] = "\0";
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
        wordInserter(wordList, token);
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
    printList(wordList);
    char* return_phrase = "";
    char* spacer = " ";
    *traverser = wordList;
    while(traverser != 0){
        strcat(return_phrase, traverser->word);
        strcat(return_phrase, spacer);
    }
    free(changer_string);
    return return_phrase;
}

int main(){
    char* eggs = scramble_prompt("Hello World, Beautiful Day\n");
    printf("%s\n", eggs);
}