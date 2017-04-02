# build everything
make clean
make

echo ""
echo "running in the background."
echo "check back later on"

echo 1024 | ./normalmat > reports/normalmat.txt &
echo 1024 | ./transposemat > reports/transposemat.txt &
echo 1024 | ./blockedmat 2 > reports/blockedmat_2.txt &
echo 1024 | ./blockedmat 4 > reports/blockedmat_4.txt &
echo 1024 | ./blockedmat 8 > reports/blockedmat_8.txt &
echo 1024 | ./threadedmat 2 > reports/threadedmat_2.txt &
echo 1024 | ./threadedmat 4 > reports/threadedmat_4.txt &
echo 1024 | ./threadedmat 8 > reports/threadedmat_8.txt &
