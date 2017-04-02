# build everything
make clean
make normalmat
make transposemat
make blockedmat
make threadedmat

echo ""
echo "running in the background."
echo "check back later on"

echo 16384 | ./normalmat > reports/normalmat.txt &
echo 16384 | ./transposemat > reports/transposemat.txt &
echo 16384 | ./blockedmat 2 > reports/blockedmat_2.txt &
echo 16384 | ./blockedmat 4 > reports/blockedmat_4.txt &
echo 16384 | ./blockedmat 8 > reports/blockedmat_8.txt &
echo 16384 | ./threadedmat 2 > reports/threadedmat_2.txt &
echo 16384 | ./threadedmat 4 > reports/threadedmat_4.txt &
echo 16384 | ./threadedmat 8 > reports/threadedmat_8.txt &
