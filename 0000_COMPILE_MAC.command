cd "${0%/*}"
mkdir BUILDMAC
gcc -c empty.c
gcc -c main.c
gcc -o BUILDMAC/test empty.o main.o -framework SDL2