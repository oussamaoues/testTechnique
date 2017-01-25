#declaration des variables
CC=gcc
CFLAGS=-c 

#les dépendances
all: encoder

encoder: main.o encoder.o
	$(CC) main.o encoder.o -o encoder

main.o: main.c
	$(CC) $(CFLAGS) main.c

encoder.o: encoder.c
	$(CC) $(CFLAGS) encoder.c

clean: 
	rm -rf *o encoder
	

