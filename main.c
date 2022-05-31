#include <stdlib.h>
#include <stdio.h>
#include "leitura.h"

// TODO: Redigir Relatório (1)
// TODO: Críticas e Propostas de Melhorias (12)
// TODO: Descrição da experiência do Projeto (13)

//genoma grande.txt, pos genes grande.csv, fragmentos pequeno.txt)
int main(void)
{
    FILE *atividade_genica = fopen("./Saida/atividade_genica.txt", "w");
    FILE *pos_fragmentos = fopen("./Saida/pos_fragmentos.csv", "w+");
    FILE *genoma = fopen("./Entrada/genoma_teste.txt", "r");
    FILE *pos_genes = fopen("./Entrada/pos_genes_teste.csv", "r");
    FILE *fragmentos = fopen("./Entrada/fragmentos_teste.txt", "r");


    contagem_leituras(genoma, pos_genes, fragmentos, pos_fragmentos, 2, 2, atividade_genica);



    fclose(atividade_genica);
    fclose(pos_fragmentos);
    fclose(genoma);
    fclose(pos_genes);
    fclose(fragmentos);
    return 0;
}

// int contar_linhas(FILE *arquivo)
// {
//     // FILE *fileptr;
//     int count_lines = 0;
//     char filechar[40], chr;

//     // printf("Enter file name: ");
//     // scanf("%s", filechar);
//     // fileptr = fopen(filechar, "r");
//    //extract character from file and store in chr
//     chr = fgetc(arquivo);
//     while (chr != EOF)
//     {
//         //Count whenever new line is encountered
//         if (chr == 'n')
//         {
//             count_lines = count_lines + 1;
//         }
//         //take next character from file.
//         chr = fgetc(arquivo);
//     }
//     // fclose(arquivo); //close file.
//     // printf("There are %d lines in %s  in a file\n", count_lines, filechar);
//     return count_lines;
// }
