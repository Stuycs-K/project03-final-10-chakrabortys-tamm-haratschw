all: client server prompts
client: telephone_client client_networking.o

	gcc -o client telephone_client client_networking.o

server: telephone_server
	gcc -o server telephone_server

telephone_client: client.c client.h
	gcc -c client.c

client_networking.o: client_networking.c client.h
	gcc -c client_networking.c

telephone_server: server.c server.h
	gcc -c server.c

clean:
	rm *.o
	rm telephone_server
	rm telephone_client
	rm *~
