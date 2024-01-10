# Dev Log:

## William H

### 2024-01-08 - Added randomer() function to scramble_prompt.c, as part of designing the game.
Completed basic functionality of randomer(), which, given a word, chooses a random word index to change the alphabet letter-value of, to a random alphabet letter-value in ASCII.
This function is called by scramble(), which holds the greater logic behind scrambling phrases/individual words.

### 2024-01-09 - Added features to scramble_prompt.c, to build the game.
Completed basic functionality of scramble_prompt() and usage of linked lists within scramble_prompt.c. The usage of a linked list to store separated words of the original phrase necessitated the creation of scramble_prompt.h header file to define the linked list struct. More testing needed.




