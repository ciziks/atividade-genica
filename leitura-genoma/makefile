all: arquivos.o ordenacao.o leitura.o Main
	gcc main.o arquivos.o leitura.o ordenacao.o -g -Wall -o all -lm 

ordenacao.o: ordenacao.c
	gcc -c ordenacao.c -o ordenacao.o

leitura.o: leitura.c
	gcc -c leitura.c -o leitura.o

arquivos.o: arquivos.c 
	gcc -c arquivos.c -o arquivos.o

Main:
	gcc -c main.c -I./exercicio -o main.o

run:
	./all
