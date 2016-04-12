readline.o: readline.c readline.h
	gcc -c readline.c

dogs.o: dogs.c dogs.h
	gcc -c dogs.c

records.o: records.c dogs.h readline.h
	gcc -c records.c

records: records.o dogs.o readline.o
	gcc -o records records.o dogs.o readline.o
