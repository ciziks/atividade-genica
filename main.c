#include <stdlib.h>
#include <stdio.h>
#include "leitura.h"

// TODO: Redigir Relatório (1)
// TODO: Críticas e Propostas de Melhorias (12)
// TODO: Descrição da experiência do Projeto (13)

//genoma grande.txt, pos genes grande.csv, fragmentos pequeno.txt)
int main(void)
{
    FILE *atividade_genica = fopen("./Saida/atividade_genica.txt", "w+");
    FILE *pos_fragmentos = fopen("./Saida/pos_fragmentos.txt", "w+");
    FILE *genoma_grande = fopen("./Entrada/genoma_grande.txt", "r");
    FILE *pos_genes_grande = fopen("./Entrada/pos_genes_grande.txt", "r");
    FILE *fragmentos_pequeno = fopen("./Entrada/fragmentos_pequeno.txt", "r");

    printf("^");
    contagem_leituras(genoma_grande, pos_genes_grande, fragmentos_pequeno, pos_fragmentos, 10, 300, atividade_genica);
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

