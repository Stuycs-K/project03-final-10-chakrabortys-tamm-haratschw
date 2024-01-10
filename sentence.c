#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct node {char *word; struct node *nextNode};

struct node* structHeap(char *word){
    struct node* node = calloc(1, sizeof(struct node));
    node->word = calloc(1, sizeof(word));
    printf("Heapy, size given to node var word: %d, size of word %s: %d\n", sizeof(node->word), word, sizeof(word));
    strcpy(node->word, word);
    return node;
}

//insert word at end of linked list
int wordInserter(struct node *list, char* word){
    struct node *s = structHeap(word);
    list->nextNode = s;
    printf("Word given %s\n", word);
    s->nextNode = NULL;
    return 0;
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
    printf("a\n");
    char * changer_string = strdup(string);
    char * token, *saveptr;
    //creates linked_list
    struct node *wordList = NULL;
    const char* delimiter = " ";
    printf("b\n");
    while((token = strsep(&changer_string, delimiter)) != NULL){
        wordInserter(&wordList, token);
        //this if-statement skips the processing for empty tokens using `continue`.
        if(*token == '\0'){
            continue;
        }
    }
    printf("c\n");
    //loop through completed linked-list
    struct node *traverser = wordList;
    char* word;
    char* updated_word;
    while(traverser != NULL){
        strcpy(word, traverser->word);
        strcpy(updated_word, scramble(word));
        strcpy(traverser->word, updated_word);
        traverser = traverser->nextNode;
    }
    printf("d\n");
    printList(wordList);
    printf("e\n");
    char* return_phrase = "";
    char* spacer = " ";
    traverser = wordList;
    while(traverser != NULL){
        strcat(return_phrase, traverser->word);
        strcat(return_phrase, spacer);
    }
    printf("f\n");
    free(changer_string);
    return return_phrase;
}

int main(){
    char* eggs = scramble_prompt("Hello World, Beautiful Day\n");
    printf("%s\n", eggs);
}