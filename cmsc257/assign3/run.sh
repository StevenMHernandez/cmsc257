# build everything
make clean
make

echo "running in the background."
echo "check back later on"

echo 1024 | ./normalmat > reports/normalmat.txt &
echo 1024 | ./transposemat > reports/transposemat.txt &
echo 1024 | ./blockedmat > reports/blockedmat.txt &
echo 1024 | ./threadedmat > reports/threadedmat.txt &
