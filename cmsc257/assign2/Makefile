# Make environment
INCLUDES=-I.
CC=gcc
CFLAGS=-I. -c -g -Wall -Wextra $(INCLUDES)
LINKARGS=-lm
LIBS=-lm

# Files
OBJECT_FILES=	cmsc257-assign2.o cmsc257-assign2-functions.o

# Productions
all : cmsc257-assign2

cmsc257-assign2 : $(OBJECT_FILES)
	$(CC) $(LINKARGS) $(OBJECT_FILES) -o $@ $(LIBS)

cmsc257-assign2.o : cmsc257-assign2.c cmsc257-assign2-functions.h
	$(CC) $(CFLAGS) $< -o $@

cmsc257-assign2-functions.o : cmsc257-assign2-functions.c cmsc257-assign2-functions.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f cmsc257-assign2 $(OBJECT_FILES)
