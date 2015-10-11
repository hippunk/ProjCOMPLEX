# définition des variables
CC = gcc
CFLAGS = -O3 -Wall --std=c11

# désactivation des règles implicites
.SUFFIXES:

all: main.o instance.o algo_approche.o
	$(CC) $(CFLAGS) main.o instance.o algo_approche.o -o main
 
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o 
  
instance.o: instance.c instance.h
	$(CC) $(CFLAGS) -c instance.c -o instance.o
	
algo_approche.o: algo_approche.c
	$(CC) $(CFLAGS) -c algo_approche.c -o algo_approche.o



# suppression des fichiers temporaires
clean:
	rm -rf *.o
 
# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf Programme
