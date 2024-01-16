#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void scrambleWord(char* word){
    char* list = calloc(strlen(word), sizeof(list));
    char* modSTR = list;
    int i = 0;
    for(i = 0; i < strlen(word); i++){
        list[i] = *(word + i);
    }
    list[i] = '\0';
    srand(time(NULL));
    int wordLength = strlen(word);
    if (wordLength > 0) {
        int randomIndex = rand() % wordLength;
        // Ensure the character at the random index is an alphabet letter
        if (isalpha(word[randomIndex])) {
            char baseChar = isupper(word[randomIndex]) ? 'A' : 'a';
            int offset = rand() % 26;
            word[randomIndex] = baseChar + offset;
        }
    }
}

char* control_function(char* string){
    //first, count number of words in the phrase
    char * testing_string = strdup(string);
    int word_counter = 0;
    int inWordFlag = 0;
    for(int i = 0; testing_string[i] != '\0'; i++){
        if(testing_string[i] == ' ' || testing_string[i] == '\t' || testing_string[i] == '\n'){
            if(inWordFlag){
                word_counter++;
                inWordFlag = 0;
            }
        }else{
            //flag to 1 means not inside a word
            inWordFlag = 1;
        }
    }
    if(inWordFlag){
        word_counter++;
    }
    printf("%d\n", word_counter);
    //allocate array of strings (to modify words)
    char** wordArray = malloc(word_counter * sizeof(char*));
    if(wordArray == NULL){
        fprintf(stderr, "Memory allocation for wordArray failed\n");
        exit(EXIT_FAILURE);
    }
    char* token = strtok(testing_string, " \t\n");
    int i = 0;
    while(token != NULL){
        wordArray[i] = strdup(token);
        if(wordArray[i] == NULL){
            fprintf(stderr, "Memory allocation for wordArray element failed\n");
            exit(EXIT_FAILURE);
        }
        i++;
        token = strtok(NULL, " \t\n");
    }
    for(int i = 0; i < word_counter; i++){
        printf("Word %d: %s\n", i, wordArray[i]);
    }
    //loop through array, modifying each word
    for(int i = 0; i < word_counter; i++){
        scrambleWord(wordArray[i]);
    }
    //wordArray is now modified
    for(int i = 0; i < word_counter; i++){
        printf("Modified word %d: %s\n", i, wordArray[i]);
    }
    //Building the result string
    int resultLength = 0;
    for(int i = 0; i < word_counter; i++){
        resultLength += strlen(wordArray[i]) + 1; //+1 for space between words
    }
    char* result = calloc(1, resultLength);
    if(result == NULL){
        fprintf(stderr, "Memory allocation for result string failed\n");
        exit(EXIT_FAILURE);
    }
    result[0] = '\0';
    for(int i = 0; i < word_counter; i++){
        strcat(result, wordArray[i]);
        strcat(result, " "); //add space between words
    }
    for(int i = 0; i < word_counter; i++){
        free(wordArray[i]);
    }
    free(wordArray);
    free(testing_string);
    return result;
}

int main(){
    char inputBuffer[1000];
    printf("Enter a phrase: ");
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    if(strlen(inputBuffer) > 0 && inputBuffer[strlen(inputBuffer) - 1] == '\n'){
        inputBuffer[strlen(inputBuffer) - 1] = '\0';
    }
    char * result = control_function(inputBuffer);
    printf("Modified Phrase: %s\n", result);
    //free result memory
    free(result);
    return 0;
}