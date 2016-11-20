
# Makefile with flags
# *******************************
# Paramaters for cross-compiler, warning flags, and gdb flags

CC = gcc
CFLAGS = -Wall -g

# *******************************
# Entries for executables

justify: justify.o word.o line.o
	$(CC) $(CFLAGS) -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h
	$(CC) $(CFLAGS) -c justify.c

word.o: word.c word.h
	$(CC) $(CFLAGS) -c word.c

line.o: line.c line.h
	$(CC) $(CFLAGS) -c line.c