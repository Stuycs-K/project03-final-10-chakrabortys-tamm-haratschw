#include "client.h"
#include "server.h"

const char* words[] = {

};

void readToList(const char* fileName){
    FILE* file = fopen(fileName, "r");
    if(file == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char word[256];
    int index = 0;
    while(fscanf(file, "%s", word) == 1){
        words[index] = strdup(word);
        index++;
    }
    fclose(file);
}

int readDictionary(){
    readToList("/usr/share/dict/words");
    return 0;
}