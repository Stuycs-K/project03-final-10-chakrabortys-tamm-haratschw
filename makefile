all: client server prompts
client: client.o client_networking.o
	gcc -o client client.o client_networking.o

server: server.o client_networking.o
	gcc -o server server.o client_networking.o

client.o: client.c client.h
	gcc -c client.c

server.o: server.c server.h
	gcc -c server.c

client_networking.o: client_networking.c client_networking.h
	gcc -c client_networking.c

prompts: scramble_prompt.c get_prompt.c prompts.h
	gcc -c scramble_prompt.c
	gcc -c get_prompt.c

clean:
	rm *.o
	rm server
	rm client
	rm *~