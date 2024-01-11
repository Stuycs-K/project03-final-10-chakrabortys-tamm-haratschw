all: client server prompts
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

prompts: scramble_prompt.c get_prompt.c prompts.h
	gcc -c scramble_prompt.c
	gcc -c get_prompt.c

clean:
	rm *.o
	rm server
	rm client
	rm *~