#declaration des variables
CC=gcc
CFLAGS=-c 

#les dépendances
all: encoder

encoder: main.o encoder.o
	$(CC) main.o encoder.o -o encoder -W -Wall -ansi -pedantic

main.o: main.c
	$(CC) $(CFLAGS) main.c -W -Wall -ansi -pedantic

encoder.o: encoder.c
	$(CC) $(CFLAGS) encoder.c -W -Wall -ansi -pedantic

clean: 
	rm -rf *o encoder

mrproper: clean
	rm -rf encoder
	

