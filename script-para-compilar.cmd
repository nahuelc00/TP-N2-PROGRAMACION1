gcc -c main.c -o main.o
gcc -c abm.c -o abm.o
gcc -c grafico.c -o grafico.o
gcc -c ordenar.c -o ordenar.o
gcc -c validaciones.c -o validaciones.o
gcc main.o abm.o grafico.o ordenar.o validaciones.o -o programa.exe