mkdir BUILD64
:: Generate resource file for program icon
windres ct.rc -O coff -o ct.res
:: Compile and link
gcc -c empty.c
gcc -c main.c
gcc -o BUILD64/ctwin.exe empty.o main.o ct.res -Llib64/ -lSDL2main -lSDL2
:: Done
pause