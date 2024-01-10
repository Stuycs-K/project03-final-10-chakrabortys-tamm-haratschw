all: client server
client: client.o client_networking.o
	gcc -o client client.o client_networking.o

server: server.o
	gcc -o server server.o

client.o: client.c client.h
	gcc -c client.c

server.o: server.c server.h
	gcc -c server.c

client_networking.o: client_networking.c client.h
	gcc -c client_networking.c

clean:
	rm *.o
	rm server
	rm client
	rm *~