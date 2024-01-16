all: client server prompts random_prompt
client: client.o networking.o
	gcc -o client client.o networking.o

server: server.o networking.o
	gcc -o server server.o networking.o

client.o: client.c client.h
	gcc -c client.c

server.o: server.c server.h
	gcc -c server.c

networking.o: networking.c networking.h
	gcc -c networking.c

prompts: scramble_prompt.c get_prompt.c
	gcc -c scramble_prompt.c
	gcc -c get_prompt.c

random_prompt: random_prompt.c random_prompt.h
	gcc -c random_prompt.c

clean:
	rm *.o
	rm server
	rm client
	rm *~