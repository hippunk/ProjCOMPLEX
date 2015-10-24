# définition des variables
CC = gcc
CFLAGS = -O2 -g -Wall --std=c11

# désactivation des règles implicites
.SUFFIXES:

all: main.o instance.o algo_approche.o test.o node.o tabStack.o exacte.o
	$(CC) $(CFLAGS) main.o instance.o algo_approche.o test.o node.o tabStack.o exacte.o -o main
 
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o 
  
instance.o: instance.c instance.h
	$(CC) $(CFLAGS) -c instance.c -o instance.o
	
algo_approche.o: algo_approche.c
	$(CC) $(CFLAGS) -c algo_approche.c -o algo_approche.o
	
test.o: test.c
	$(CC) $(CFLAGS) -c test.c -o test.o

exacte.o: exacte.c
	$(CC) $(CFLAGS) -c exacte.c -o exacte.o
	
node.o: node.c
	$(CC) $(CFLAGS) -c node.c -o node.o

tabStack.o: tabStack.c
	$(CC) $(CFLAGS) -c tabStack.c -o tabStack.o


# suppression des fichiers temporaires
clean:
	rm -rf *.o
 
# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf main
	rm -rf memcheck
	
	
memcheck: mrproper all
	valgrind --tool=massif --stacks=yes --time-unit=B --massif-out-file=memcheck.massif ./main
	ms_print memcheck.massif > memcheck
	rm -rf memcheck.massif
