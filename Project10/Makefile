# Makefile with flags
# *******************************
# Paramaters for cross-compiler, warning flags, and gdb flags

CC = gcc
CFLAGS = -Wall -g

# *******************************
# Entries for executables

roster: roster.o player.o readline.o
	$(CC) $(CFLAGS) -o roster roster.o player.o readline.o

roster.o: roster.c player.h readline.h
	$(CC) $(CFLAGS) -c roster.c

player.o: player.c player.h
	$(CC) $(CFLAGS) -c player.c

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c readline.c
