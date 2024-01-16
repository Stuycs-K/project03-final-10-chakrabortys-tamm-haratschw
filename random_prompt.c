#include "random_prompt.h"

#define MAX_PHRASE_LENGTH 1000

char * randomPrompt(int numWords){
    srand(time(NULL));
    char * phrase = malloc(MAX_PHRASE_LENGTH * sizeof(char));
    if(phrase == NULL){
        fprintf(stderr, "Memory allocation for phrase failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(phrase, "");
    printf("Random Sentence: ");
    for(int i = 0; i < numWords; ++i){
        int randomIndex = rand() % (sizeof(words) / sizeof(words[0]));
        strcat(phrase, words[randomIndex]);
        if(i < numWords - 1){
            strcat(phrase, " ");
        }
    }
    return phrase;
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void promptCaller(){
    srand(time(NULL));
    int numWords = getRandomNumber(5, 10);
    char* generatedPhrase = randomPrompt(numWords);
    printf("%s\n", generatedPhrase);
    free(generatedPhrase);
}