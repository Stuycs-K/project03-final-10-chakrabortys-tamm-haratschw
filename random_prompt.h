#ifndef RANDOM_PROMPT_H
#define RANDOM_PROMPT_H

#include "client.h"
#include "server.h"
#include "wordlist.c"

char * randomPrompt(int numWords);
int getRandomNumber(int min, int max);
void promptCaller();

#endif