# Makefile with flags
# *******************************
# Paramaters for cross-compiler, warning flags, and gdb flags

CC = gcc
CFLAGS = -Wall -g

# *******************************
# Entries for executables

stack_client:stack_client.o stack.o
	$(CC) $(CFLAGS) -o stackclient stack_client.o stack.o
stack_client.o:stack_client.c stack.h
	$(CC) $(CFLAGS) -c stack_client.c
stack.o:stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c
