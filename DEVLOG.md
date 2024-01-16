# Dev Log:

## Sudipta Chakraborty

### 2024-01-03 - Proposal Creation
Worked with the rest of the group to come up with the contents to PROPOSAL.md, (30m)

### 2024-01-04 - Diagram of Server and Client 
Created a diagram that distinguished the functionalities of the various parts of the project,
which was shared with the rest of the group. (1h)

### 2024-01-05 Project File Structure
Using the diagram, we decided to plan out our project file structure before writing any of the code.
This included some painful makefile debugging, work to get the different files to compile. The goal 
was to have a runnable client and server file, where each would use functions from networking.c but
also have their own respective header files, with the addition of the prompt handling files. We did
think about having dedicated C files for the logging, but decided to add it as functions in server. (30m)

### 2024-01-09 Initial Clientside Framework
Created a general idea of how the user should be able to interact with the game, focusing primarily on the
gameplay loop at first. Corrected some additional errors with the makefile as well. (40m)

### 2024-01-10 Server and Client Networking
Added the server and client commands in networking.c to be used in server.c and client.c. A portion of this
was from previous labs, but had to be changed significantly to fit this project. The old code additionally
had errors that needed to be fixed before it could be fully implemented. (50m)


### 2024-01-11 Connection Between Server and Client
Successful connection established between the server and client! Most of the time was spent on rearranging parts
of the code, and swapping out lines in networking.c until the connection finally happened. A lot of time was also
spent on adding in select, in order for multiple clients to connect at the same time. A lot of the time was spent
learning how select worked. (60m)

### 2024-01-12 Sighandler Usage
Attempt at implementing turn skipping with SIGINT using a sighandler in client.c. However, using CTRL+C for SIGINT
did not work with fgets(), as the CTRL+C would be interpreted as input rather than as a trigger for the signal. The
initial idea was to use a static variable to set a custom string to be sent to the server, rather than somehow sending
the signal directly to the server. (30m)

### 2024-01-14 Multiplayer
Removed the sighandler from client.c in order to pursue the multiplayer implementation using select. Since I was absent
on the day that this was explained, this took much longer than expected, and I wasn't able to get the code in a state where
it would compile. A majority of the time was spent staring at select documentation and the code sample published on the website,
yet to no avail. Due to the state of the code, I didn't commit it, but instead invited everyone else to a live share session. (80m)

### 2024-01-15 Final Select Pain
Continued pursuit of trying to get select to work. Eventually, we got the connection between the server and clients working! Clients
would show up as connected to the server, and the server rightfully indicated it. However, I was not able to get it to work, and the
data transfer betweenhte server and the client does not work. (190m)
===========
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
