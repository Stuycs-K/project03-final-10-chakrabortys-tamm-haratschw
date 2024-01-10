#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define buffSize 128

char* scrambleWord(char* string){
    char* list = calloc(strlen(string), sizeof(list));
    char* modSTR = list;
    int i = 0;
    for(i = 0; i < strlen(string); i++){
        list[i] = *(string + i);
    }
    list[i] = "\0";
    srand(time(NULL));
    while(modSTR < list + strlen(string) - 1){
        modSTR += 3;//rand() % (strlen(string) / 3);
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

char* replace_Word(char* string){
    //read from /usr/share/dict/words and replace words with random words that have a matching first letter
    char word[buffSize];
    FILE* o_file = fopen("/usr/share/dict/words", "r");
    int bytes;
    int i = 0;
    while(i < 18){
        fgets(word, buffSize, o_file);
    }
    printf("%s\n", word);
    return *word;
    

    
    
}

int main(){
    char* eggs = scrambleWord("Hello ] Yes . World , This is Grammar Intact !\n");
   // char* word = replace_Word("Replacable");
}