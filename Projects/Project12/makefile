# Makefile with flags
# *******************************
# Paramaters for cross-compiler, warning flags, and gdb flags

CC = gcc
CFLAGS = -Wall -g

# *******************************
# Entries for executables

records: records.o dogs.o readline.o
	$(CC) $(CFLAGS) -o records records.o dogs.o readline.o

records.o: records.c dogs.h readline.h
	$(CC) $(CFLAGS) -c records.c

dogs.o: dogs.c dogs.h
	$(CC) $(CFLAGS) -c dogs.c

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c readline.c




