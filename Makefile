# définition des variables
CC = gcc
CFLAGS = -O3 -Wall --std=c11

# désactivation des règles implicites
.SUFFIXES:

all: main.o instance.o
	$(CC) $(CFLAGS) main.o instance.o -o main
 
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o 
  
instance.o: instance.c instance.h
	$(CC) $(CFLAGS) -c instance.c -o instance.o 



# suppression des fichiers temporaires
clean:
	rm -rf *.o
 
# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf Programme
