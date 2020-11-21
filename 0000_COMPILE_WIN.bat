mkdir BUILD
windres ct.rc -O coff -o ct.res
gcc -c empty.c
gcc -c main.c
gcc -o BUILD/ctwin.exe empty.o main.o ct.res -Llib/ -lSDL2main -lSDL2
pause