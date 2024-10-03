SRC=Show.c
EXEC=Show
CC=gcc
LIBS=-lncurses
CFLAGS=-Wall

Show: Show.o

%:	%.c
	$(CC) $(CFLAGS) $< $(LIBS) -o $@

clean: 
	rm *.o Show
