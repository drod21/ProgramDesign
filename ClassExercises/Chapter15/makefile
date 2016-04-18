primetest: primetest.o prime.o boolean.o
	gcc -o primetest prime.o primetest.o boolean.o

primetest.o: primetest.c prime.h
	gcc -c primetest.c

prime.o: prime.c prime.h
	gcc -c prime.c

boolean.o: boolean.h boolean.c
	gcc -c boolean.c
