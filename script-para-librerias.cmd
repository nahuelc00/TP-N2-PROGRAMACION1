gcc -c main.c -o main.o
gcc -c validaciones.c -o validaciones.o
gcc -c grafico.c -o grafico.o
gcc -c ordenar.c -o ordenar.o
gcc -c abm.c -o abm.o
gcc validaciones.o abm.o ordenar.o grafico.o main.o -o programa.exe