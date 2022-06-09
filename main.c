#include <stdlib.h>
#include <stdio.h>
#include "leitura.h"

// TODO: Redigir Relatório (1)
// TODO: Críticas e Propostas de Melhorias (12)
// TODO: Descrição da experiência do Projeto (13)

//genoma grande.txt, pos genes grande.csv, fragmentos pequeno.txt)
int main(void)
{
    FILE *genoma = fopen("./Entrada/genoma_grande.txt", "r");
    FILE *pos_genes = fopen("./Entrada/pos_genes_grande.csv", "r");
    FILE *fragmentos = fopen("./Entrada/fragmentos_grande.txt", "r");

    FILE *atividade_genica = fopen("./Saida/atividade_genica.txt", "w");
    FILE *pos_fragmentos = fopen("./Saida/pos_fragmentos.csv", "w+");

    contagem_leituras(genoma, pos_genes, fragmentos, pos_fragmentos, 10000, 30000, atividade_genica);

    fclose(atividade_genica);
    fclose(pos_fragmentos);
    fclose(genoma);
    fclose(pos_genes);
    fclose(fragmentos);

    return 0;
}
