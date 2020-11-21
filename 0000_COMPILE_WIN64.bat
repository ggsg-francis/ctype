mkdir BUILD64
windres ct.rc -O coff -o ct.res
gcc -c empty.c
gcc -c main.c
gcc -o BUILD64/ctwin.exe empty.o main.o ct.res -Llib64/ -lSDL2main -lSDL2
pause