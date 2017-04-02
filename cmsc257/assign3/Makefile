normalmat : normalmat.o base_matrix_functions.o
	gcc normalmat.c -g -o normalmat -lrt

transposemat : transposemat.o base_matrix_functions.o
	gcc transposemat.c -g -o transposemat -lrt

blockedmat : blockedmat.o base_matrix_functions.o
	gcc blockedmat.c -g -o blockedmat -lrt

threadedmat : threadedmat.o base_matrix_functions.o
	gcc threadedmat.c -g -o threadedmat -lrt

clean :
	rm -f normalmat transposemat blockedmat threadedmat normalmat.o transposemat.o blockedmat.o threadedmat.o $(OBJECT_FILES)
