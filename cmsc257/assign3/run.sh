# build everything
gcc normalmat.c -o normalmat.out
gcc transposemat.c -o transposemat.out
gcc blockedmat.c -o blockedmat.out
gcc threadedmat.c -o threadedmat.out

echo 100 | ./normalmat.out > reports/normalmat.txt
echo 100 | ./transposemat.out > reports/transposemat.txt
echo 100 | ./blockedmat.out > reports/blockedmat.txt
echo 100 | ./threadedmat.out > reports/threadedmat.txt
