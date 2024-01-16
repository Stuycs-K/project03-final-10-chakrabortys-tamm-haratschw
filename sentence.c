#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct node {char *word; struct node *nextNode;};

void structHeap(struct node * start, char* word){
    struct node * temp = start;
    while (temp->nextNode != 0){
        temp = temp->nextNode;
    }
    temp->nextNode = malloc(sizeof(temp));
    temp->nextNode->word = word;
    temp->nextNode->nextNode = 0;
    printf("Done heaping sentence %s.\n", temp->nextNode->word);
}

char** splitter(char* sentence){
    int spaceCounter = 0;
    int i;
    for(i = 0; i < strlen(sentence); i++){
        if(sentence[i] == 32){
            spaceCounter++;
        }
    }
    printf("Space count = %d\n", spaceCounter);
    char** wordList = malloc(spaceCounter * sizeof(char*));
    char* newSentence = malloc(strlen(sentence) * sizeof(sentence));
    i = 0;
    strcpy(newSentence, sentence);
    printf("Splitting string %s\n", newSentence);
    while( (wordList[i] = strsep(&newSentence, " ")) != NULL ){
        printf("%s\n", wordList[i]);
        i++;
    }
    printf("Spl it\n");
    return wordList;
}

struct node * initializeNodes(char* sentence){
    struct node * start;
    char** split = splitter(sentence);
    start = malloc(sizeof(struct node));
    int spaceCount = 0;
    int i = 0;
    printf("Counting Spaces\n");
    printf("%s", split[i]);
    while(split[i + 1] != NULL){
        printf("Count 1\n");
        spaceCount++;
        i++;
    }
    int size = spaceCount + 1;
    printf("Starting to initialize\n");
    if(start == 0){
        printf("failed to initialize");
    }
    for(i = 0; i < size; i++){
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
void free_list(struct node *start){
    struct node *temp;
    while (start != NULL) {
        printf("Freeing %s\n", start->word);
        temp = start; 
        start = start->nextNode;
        free(temp->word);
        free(temp);
    }
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
    srand(time(NULL));
    while(modSTR < list + strlen(string) - 1){
        modSTR += 3;//rand() % (strlen(string) / 3);
        if( (*modSTR < 48) || (*modSTR > 57 && *modSTR < 65) || (*modSTR > 90 && *modSTR < 97) || (*modSTR > 122)){
            continue;//don't replace
        }
        printf("Character to be modified: %d or %c\n", *modSTR, *modSTR);
        *modSTR = rand() % 94 + 33;
        printf("Character modified into: %d or %c\n", *modSTR, *modSTR);
        sleep(1);
    }
    printf("%s\n", list);
    return list;
}

//separates the prompt into separate words, each to be passed as an argument into scramble().
char* scramble_prompt(char* string){
    char* return_phrase = calloc(strlen(string), sizeof(string));
    printf("a\n");
    struct node *wordList = NULL;
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
    char* spacer = " ";
    traverser = wordList;
    while(traverser != NULL){
        printf("Returning word %s to return_phrase\n", traverser->word);
        strcat(return_phrase, traverser->word);
        strcat(return_phrase, spacer);
        printf("This is the return phrase %s\n", return_phrase);
        traverser = traverser->nextNode;
    }
    printf("f\n");
    free_list(wordList);
    printf("g\n");/**/
    return return_phrase;
}

//expecting 1 argument, the given string
//alternatively just use scramble_prompt from the .h file and ignore executing this file
char* main(int argc, char* argv[]){
    char *raw_eggs = malloc(sizeof(argv[1]));
    raw_eggs = argv[1];
    printf("%s\n", raw_eggs);
    char* scrambled_eggs = scramble_prompt(raw_eggs);
    printf("%s\n", scrambled_eggs);

    printf("nfbniq0ubngonjgqnoj\n\n\n");
    printf("1tqejwk\n");
    //return scrambled_eggs;
}