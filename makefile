default: sentence run

get_prompt.o: get_prompt.c
	gcc -c get_prompt.o get_prompt.c

sentence.o: sentence.c
	gcc -c sentence.o sentence.c

sentence: sentence.o
	gcc -o sentence sentence.o

prompter: get_prompt.o
	gcc -o prompter get_prompt.o

run: prompter sentence
	./prompter