mkdir BUILD
:: Generate resource file for program icon
windres ct.rc -O coff -o ct.res
:: Compile and link
gcc -c empty.c
gcc -c main.c
gcc -o BUILD/ctwin.exe empty.o main.o ct.res -lgdi32
:: Done
pause