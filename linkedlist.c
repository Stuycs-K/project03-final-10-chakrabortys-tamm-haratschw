#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct node {char *word; struct node *nextNode;};

struct node* structHeap(char *word, struct node *next){
    struct node *pointer = calloc(1, sizeof(struct node));
    strcpy(pointer->word, word);
    pointer->nextNode = next;
    return pointer;
}

struct node * insert_front(struct node *list, char* word){
    struct node *s = structHeap(word, list);
    s->nextNode = list;
    return s;
}

void print_list(struct node *list){
    int counter = 0;
    struct node *traverser = list;
    while(traverser != 0){
        printf("[Index Number: %d] Word: %s\n", counter, traverser->word);
        counter++;
        traverser = traverser->nextNode;
    }
}

struct node * free_list(struct node * list){
    struct node *traverser = list;
    struct node *temp;
    while(traverser != 0){
        temp = traverser;
        traverser = traverser->nextNode;
        free(temp);
    }
    return 0;
}

struct node * linkedlistphrasereturner(struct node *list){
    
}

struct node * linkedlistwordreplacer(struct node * list){

}

struct node * linkedlistpopulate(struct node * list){

}

struct node * linkedlistinitialize(struct node * list){

}
