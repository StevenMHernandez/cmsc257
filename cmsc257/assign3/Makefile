normalmat : normalmat.o base_matrix_functions.o
	gcc normalmat.c -o normalmat -lrt

transposemat : transposemat.o base_matrix_functions.o
	gcc transposemat.c -o transposemat -lrt

blockedmat : blockedmat.o base_matrix_functions.o
	gcc blockedmat.c -o blockedmat -lrt

threadedmat : threadedmat.o base_matrix_functions.o
	gcc threadedmat.c -o threadedmat -lrt

base_matrix_functions.o : base_matrix_functions.c
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

clean :
	rm -f normalmat transposemat blockedmat threadedmat normalmat.o transposemat.o blockedmat.o threadedmat.o $(OBJECT_FILES)
