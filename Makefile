# définition des variables
CC = gcc
CFLAGS = -O2 -g -Wall --std=c11

# désactivation des règles implicites
.SUFFIXES:

all: main.o instance.o algo_approche.o test.o exact.o bornes.o
	$(CC) $(CFLAGS) main.o instance.o algo_approche.o test.o exact.o bornes.o -o main
 
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o 
  
instance.o: instance.c instance.h
	$(CC) $(CFLAGS) -c instance.c -o instance.o
	
algo_approche.o: algo_approche.c
	$(CC) $(CFLAGS) -c algo_approche.c -o algo_approche.o
	
test.o: test.c
	$(CC) $(CFLAGS) -c test.c -o test.o

exact.o: exact.c
	$(CC) $(CFLAGS) -c exact.c -o exact.o
	
bornes.o: bornes.c
	$(CC) $(CFLAGS) -c bornes.c -o bornes.o
	


# suppression des fichiers temporaires
clean:
	rm -rf *.o
 
# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf main
	rm -rf memcheck
	rm -rf memcheck.massif
	
	
memcheck: mrproper all
	valgrind --tool=massif --stacks=yes --time-unit=B --massif-out-file=memcheck.massif ./main
	ms_print memcheck.massif > memcheck
	rm -rf memcheck.massif
