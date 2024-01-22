[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/SQs7pKlr)
# Telephone

### Telephonies

Group Members Here
* William Haratsch
* Sudipta Chakraborty
* Matthew Tam
  
### Project Description:
* Telephone game that cycles between connected players
* Settings for looping, and number of players, lobby to wait before starting game
* Prompts the next user in queue for their sentence, and scrambles/omits parts of the sentence
* Saves a log of the progression of sentences once it has ended as a file
  
### Instructions:

How does the user install/compile/run the program.
The user must first compile all the necessary files by running `make all`. After compilation, the host will run the server file by running `./server` in the terminal, and the clients will run `./client` in the terminal.
How does the user interact with this program?
The host must wait for all the clients to join the game before inputting the prompt/statement to be passed around. The game will not function properly until the necessary amount of clients (3 by default, but can be changed with the PLAYER_MIN define in `server.h`) have connected. Once the correct number of clients have connected to the server, the host can start the game by entering the prompt they wish to be passed on. As the statement is cycled around, the clients will wait for their turn. Once it is their turn, the terminal will provided them a partially scrambled version of what was previously written, and the program will ask them to enter a sentence resembling the original. If the user wishes to skip their turn, they can type "SKIP", or let the program automatically time out after 30 seconds. Once the last player has completed their prompt, the server will send all the clients the initial prompt, and conclude the game. The server host will have access to a log of what the original prompt was, the scrambled prompts, and what the players wrote.
