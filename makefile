all: client telephone_server prompts
client: telephone_client client_networking.o
	gcc -o client client_networking.o

telephone_client: client.c client.h
	gcc -c client.c

client_networking.o: client_networking.c client.h
	gcc -c client_networking.c

telephone_server: server.c server.h
	gcc -c server.c

prompts: scramble_prompt get_prompt

scramble_prompt: scramble_prompt.c prompts.h
	gcc -c scramble_prompt.c

get_prompt: get_prompt.c prompts.h
	gcc -c get_prompt.c

clean:
	rm *.o
	rm server.o
	rm client.o
	rm *~
