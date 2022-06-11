# Atividade Gênica

Colaboradores:
* Eduardo Monteiro;
* Lucas Ivars Cadima Ciziks;
* Pedro Henrique Freitas.

## Resumo
Projeto sobre a medição da atividade gênica de organismos, a partir de dados de sequenciameento de DNA da disciplina Estrutura de Dados II, administrada por Robson Cordeiro.

## Problema

O presente projeto visa o estudo e a aplicação dos conceitos discutidos até o momento na disciplina Estrutura de Dados II por meio de um cenário do mundo real: A extração da atividade gênica de um organismo. De forma sucinta, o objetivo final da aplicação de bioinformática é medir o nível de influência que cada gene possui em nosso organismo. Tal objetivo pode ser atingido analisando-se a quantidade de RNAs mensageiros, que são cópias transcritas de um gene em específico, presentes na célula: Quanto maior o número de mRNAs, maior a produção de proteínas e, portanto, mais influente esse gene é nas reações químicas do nosso organismo.

Uma vez estabelecido e compreendido o problema, foram implementados  na linguagem C os quatro pseudocódigos  apresentados na especificação do projeto, além de algumas funções auxiliares. Essas quatro funções juntas formam o programa principal, responsável por receber os arquivos referentes ao genoma, a posição dos genes e os fragmentos dos mRNAs, e gerando como saída a atividade gênica do organismo. Assim, durante o desenvolvimento do projeto, foi possível exercitar os conceitos acerca do problema de ordenação, além da análise de complexidade de algoritmos, apresentada neste relatório.

## Como executar?

A fim de facilitar a compilação e execução do programa, alguns comandos foram disponibilizados no Makefile. Dessa forma, é possível que qualquer um com o código em mãos possa medir a atividade gênica de um organismo e replicar os resultados obtidos. Segue a lista dos comandos a serem executados na raíz do projeto:

* make: Compila todas as funcionalidades do código e cria um executável exec na raiz do projeto;
* make clean: Remove todos os arquivos resultantes da compilação e o executável exec;
* make test: Executa o programa com o Valgrind, ferramenta de detecção de vazamentos de memória;
* make debug: Executa o programa com o GDB, ferramenta de debug;
* make run: Executa o programa principal.
