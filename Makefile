exec: ctrl_f.o ordenacao.o intersecao.o leitura.o Main
	gcc main.o ctrl_f.o leitura.o ordenacao.o intersecao.o -g -Wall -o exec -lm

ordenacao.o:
	gcc -g -c ./Ordenacao/ordenacao.c -o ordenacao.o

ctrl_f.o: ordenacao.o
	gcc -g -I ./Ordenacao -c ./CTRL_F/ctrl_f.c -o ctrl_f.o

intersecao.o:
	gcc -g -I ./CTRL_F -I ./Ordenacao -c ./Contagem_Intersecao/intersecao.c -o intersecao.o

leitura.o:
	gcc -g -I ./Contagem_Intersecao -I ./CTRL_F -c ./Contagem_Leitura/leitura.c -o leitura.o

Main:
	gcc -g -I ./CTRL_F -I ./Ordenacao -I ./Contagem_Leitura -I ./Contagem_Intersecao -c main.c -o main.o

clean:
	rm *.o exec

test: clean exec
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exec genoma_grande.txt pos_genes_grande.csv fragmentos_pequeno.txt

run: clean exec
	./exec genoma_grande.txt pos_genes_grande.csv fragmentos_pequeno.txt

debug: clean exec
	echo "r"|gdb exec
