#
# CMSC257 - Utility Library 
# Code for the CMSC257 Projects
#

# Make environment
INCLUDES=-I.
CC=gcc
CFLAGS=-I. -c -g -Wall $(INCLUDES)
LINKARGS=-lm
LIBS=-lm

# Files
OBJECT_FILES=	cmsc257-s17-assign1.o \
				cmsc257-s17-assign1-support.o

# Productions
all : cmsc257-s17-assign1

cmsc257-s17-assign1 : $(OBJECT_FILES)
	$(CC) $(LINKARGS) $(OBJECT_FILES) -o $@ $(LIBS)

cmsc257-s17-assign1.o : cmsc257-s17-assign1.c cmsc257-s17-assign1-support.h
	$(CC) $(CFLAGS) $< -o $@

cmsc257-s17-assign1-support.o : cmsc257-s17-assign1-support.c cmsc257-s17-assign1-support.h 
	$(CC) $(CFLAGS) $< -o $@

clean : 
	rm -f cmsc257-s17-assign1 $(OBJECT_FILES)
