cd "${0%/*}"
mkdir BUILDMAC
gcc -c empty.c
gcc -c main.c
gcc -o BUILDMAC/ctmac empty.o main.o -F. -framework SDL2