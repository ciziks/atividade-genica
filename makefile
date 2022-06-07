all: arquivos.o ordenacao.o leitura.o Main
	gcc main.o arquivos.o leitura.o ordenacao.o -g -Wall -o all -lm 

ordenacao.o: 
	gcc -g -c ./Ordenacao/ordenacao.c -o ordenacao.o

arquivos.o: ordenacao.o
	gcc -g -I ./Ordenacao -c ./Arquivos/arquivos.c -o arquivos.o

leitura.o: 
	gcc -g -I ./Arquivos -c ./Leitura/leitura.c -o leitura.o

Main:
	gcc -g -I ./Arquivos -I ./Ordenacao -I ./Leitura -c main.c -o main.o

run:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./all

clean:
	rm *.o all