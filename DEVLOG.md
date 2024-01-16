# Dev Log:

## William H

### 2024-01-08 - Added randomer() function to scramble_prompt.c, as part of designing the game.
Completed basic functionality of randomer(), which, given a word, chooses a random word index to change the alphabet letter-value of, to a random alphabet letter-value in ASCII.
This function is called by scramble(), which holds the greater logic behind scrambling phrases/individual words.

### 2024-01-09 - Added features to scramble_prompt.c, to build the game.
Completed basic functionality of scramble_prompt() and usage of linked lists within scramble_prompt.c. The usage of a linked list to store separated words of the original phrase necessitated the creation of scramble_prompt.h header file to define the linked list struct. More testing needed.

### 2024-01-10 - Added linked_list functions like wordInserter() and free_list().
Basic linked_list functions like wordInserter() and free_list() were added to scramble_prompt.c, to complete certain functions such as adding a word to the list and freeing the dynamically-allocated list. These functions use the linked_list struct found in the header file.

Additionally, the index randomizer was simplified, such that it no longer requires such a hefty and inefficient function to carry it out.

### 2024-01-11 - Redesigned linkedlist, more efficient use of linkedlist functions.
I redesigned the linkedlist by placing the linkedlist-specific functions in separate .c files, namely linkedlist.c and linkedlist.h. Scramble_prompt.c now only holds the functions specific to scrambling each word in the prompt. Scramble_prompt.c now calls from and includes linkedlist.c and linkedlist.h.

### 2024-01-12 - Word scrambler functionality compiles. Created controlfunction().
The main functions belonging to the word scrambler functionality, namely scrambleWord() and the various linkedlist-specific functions completed earlier, have been tested and now compile correctly. The controlfunction() function has been created, which takes arguments from main() and calls the various functions according to the specific part of the task controlfunction() is executing. The purpose of this is to ensure main() can be used for easy testing, while also having a central function calling the shots, which in this case is controlfunction().

### 2024-01-15 - Scramble_prompt.c compiles and outputs correctly, accounts for stdin.
Scramble_prompt.c is completed, as it both compiles and correctly outputs a modified phrase consisting of words, each containing a randomly-scrambled character. The file also accounts for stdin by passing the phrase given by user input from the terminal as a string to the control_function(). I realized that we in fact didn't need to use a linked list to store the string to be modified, with each word in a separate list entry. The original thinking behind the linked list was that we wouldn't know how many words were in the phrase passed by the user from stdin, so we opted for a linked list so we could dynamically change the size of the array as we modified word after word of the passed string. However, I realized that we can actually just count the number of words in the string, before creating a dynamically-allocated array with a size based on the number of words previously counted. As a result, I simplified the code and removed the linked list functionality by removing the linkedlist.c and linkedlist.h files.
