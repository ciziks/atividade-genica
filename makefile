exec: arquivo.o ordenacao.o interseccao.o leitura.o Main
	gcc main.o arquivo.o leitura.o ordenacao.o interseccao.o -g -Wall -o exec -lm 

ordenacao.o: 
	gcc -g -c ./Ordenacao/ordenacao.c -o ordenacao.o

arquivo.o: ordenacao.o
	gcc -g -I ./Ordenacao -c ./Arquivo/arquivo.c -o arquivo.o

interseccao.o: 
	gcc -g -I ./Arquivo -I ./Ordenacao -c ./Contagem_Interseccao/interseccao.c -o interseccao.o

leitura.o: 
	gcc -g -I ./Contagem_Interseccao -I ./Arquivo -c ./Contagem_Leitura/leitura.c -o leitura.o

Main:
	gcc -g -I ./Arquivo -I ./Ordenacao -I ./Contagem_Leitura -I ./Contagem_Interseccao -c main.c -o main.o

run:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./exec

clean:
	rm *.o exec

execute: clean exec
	echo "r"|gdb exec