gcc -c main.c -o main.o
gcc -c validaciones.c -o validaciones.o
gcc -c grafico.c -o grafico.o
gcc validaciones.o grafico.o main.o -o programa.exe