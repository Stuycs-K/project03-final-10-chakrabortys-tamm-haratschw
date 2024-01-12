#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct node {char *word; struct node *nextNode};

void structHeap(struct node * start, char* word){
    struct node * temp = start;
    while (temp->nextNode != 0){
        temp = temp->nextNode;
    }
    temp->nextNode = malloc(sizeof(temp));
    temp->nextNode->word = word;
    temp->nextNode->nextNode = 0;
    printf("Done heaping sentence %s\n", temp->nextNode->word);
}

char** splitter(char* sentence){
    char** wordList;
    char* newSentence = calloc(strlen(sentence), sizeof(sentence));
    int i = 0;
    for(i = 0; i < strlen(sentence); i++){
        newSentence[i] = *(sentence + i);
    }
    printf("Splitting string %s\n", newSentence);
    i = 0;
    while( (wordList[i] = strsep(&newSentence, " ")) != NULL ){
        printf("Word given = %s\n", wordList[i]);
        i++;
    }
    printf("Spl it\n");
    return wordList;
}

struct node * initializeNodes(char* sentence){
    struct node * start;
    char** split = splitter(sentence);
    start = malloc(sizeof(struct node));
    int size = 4;
    printf("Starting to initialize\n");
    if(start == 0){
        printf("failed to initialize");
    }
    for(int i = 0; i < size; i++){
        structHeap(start, split[i]);//split is the string that has been split
    }
    start->word = "Prompt:";
    return start;
}

int printList(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%s\n", temp->word);
        temp = temp->nextNode;
    }
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
    char* list = calloc(strlen(string), sizeof(list));
    char* modSTR = list;
    int i = 0;
    for(i = 0; i < strlen(string); i++){
        list[i] = *(string + i);
    }
    list[i] = "\0";
    srand(time(NULL));
    while(modSTR < list + strlen(string) - 1){
        modSTR += 4;//rand() % (strlen(string) / 3);
        if( (*modSTR < 48) || (*modSTR > 57 && *modSTR < 65) || (*modSTR > 90 && *modSTR < 97) || (*modSTR > 122)){
            continue;//don't replace
        }
        printf("Character to be modified: %d or %c\n", *modSTR, *modSTR);
        *modSTR = rand() % 94 + 33;
        printf("Character modified into: %d or %c\n", *modSTR, *modSTR);
    }
    printf("%s\n", list);
    return list;
}

//separates the prompt into separate words, each to be passed as an argument into scramble().
char* scramble_prompt(char* string){
    printf("a\n");
    struct node *wordList = NULL;
    const char* delimiter = " ";
    printf("b\n");
    wordList = initializeNodes(string);
    printf("c\n");
    //loop through completed linked-list
    struct node *traverser = wordList;
    char* word = calloc(1, sizeof(wordList[0]));
    printList(wordList);
    printf("d\n");
    while(traverser != NULL){
        strcpy(word, traverser->word);
        traverser->word = calloc(1, sizeof(wordList[0]));
        strcpy(traverser->word, scramble(word));
        printf("Moving on, added word %s to traverser\n", traverser->word);
        traverser = traverser->nextNode;
    }
    printf("e\n");
    char* return_phrase = calloc(strlen(string), sizeof(string));
    char* spacer = " ";
    traverser = wordList;
    while(traverser != NULL){
        printf("Returning word %s to return_phrase\n", traverser->word);
        strcat(return_phrase, traverser->word);
        strcat(return_phrase, spacer);
        traverser = traverser->nextNode;
    }
    printf("f\n");
    free_list(wordList);
    return return_phrase;
}

int main(){
    char* eggs = scramble_prompt("Hello World, Beautiful Day\n");
    printf("%s\n", eggs);
}