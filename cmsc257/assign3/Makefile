# Make environment
INCLUDES=-I.
CC=gcc
CFLAGS=-I. -c -g -Wall -Wextra $(INCLUDES)
LINKARGS=-lm
LIBS=-lm

# Files
OBJECT_FILES=	base_matrix_functions.o

# Productions
all : normalmat \ transposemat \ blockedmat \ threadedmat

normalmat : normalmat.o
	$(CC) $(LINKARGS) normalmat.o -o $@ $(LIBS)

normalmat.o : normalmat.c base_matrix_functions.c
	$(CC) $(CFLAGS) $< -o $@

transposemat : transposemat.o
	$(CC) $(LINKARGS) transposemat.o -o $@ $(LIBS)

transposemat.o : transposemat.c base_matrix_functions.c
	$(CC) $(CFLAGS) $< -o $@

blockedmat : blockedmat.o
	$(CC) $(LINKARGS) blockedmat.o -o $@ $(LIBS)

blockedmat.o : blockedmat.c base_matrix_functions.c
	$(CC) $(CFLAGS) $< -o $@

threadedmat : threadedmat.o
	$(CC) $(LINKARGS) threadedmat.o -o $@ $(LIBS)

threadedmat.o : threadedmat.c base_matrix_functions.c
	$(CC) $(CFLAGS) $< -o $@

base_matrix_functions.o : base_matrix_functions.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f normalmat $(OBJECT_FILES)
