# Final Project Proposal

## Group Members:

* William Haratsch
* Sudipta Chakraborty
* Matthew Tam
       
# Intentions:

A variation of the telephone game, using string manipulation to simulate errors that can arise in verbal communication.
    
# Intended usage:

Running the client and connecting to the server will lead to a (terminal) lobby in which players can input their ready inputs and wait for other users to input their ready inputs.
The game then proceeds, with a generated sentence being transmitted to the first user, who sends it to another user, except the transmission will result in garbling. The next player will then guess what the original sentence was, based on the garbled sentence, and then send that sentence to the next user, and this will repeat a certain amount of times.
  
# Technical Details:

A description of your technical design. This should include:

How you will be using the topics covered in class in the project.

*Memory allocation will be used for allocating strings for user input, and allowing for the manipulation of bytes in the strings to garble them and send them to the next user.

*Files will store previous inputs and garbled outputs, and will be read from to get a tempalte for the garbled outputs.

*Processes(forking and execing) will be used for executing a psuedo shell to write to the server.

*Sockets are necessary for communication between client(s) and server.
     
How you are breaking down the project and who is responsible for which parts.

- 
  
What data structures you will be using and how.
     
What algorithms and /or data structures you will be using, and how.

*Character arrays(strings) will be input(getline) and manipulated by changing some amount of letters or words within the array.
**Random adjustment of the bytes, to be given a new value from 32 to 126, and a way to make sure the string isn't overly changed, in letter count or proximity of letters(to avoid changing entire words unless desired).
*Sockets for communication, similar to Lab 16's networking
*Handshake algorithm to confirm users and user participation
    
# Intended pacing:

A timeline with expected completion dates of parts of the project.
