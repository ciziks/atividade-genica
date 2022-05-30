#include <stdlib.h>
#include <stdio.h>
#include "arquivos.h"

// TODO: Análise Empírica de Complexidade (10)
// TODO: Tabela e Gráficos dos arquivos dados (11)
void contagem_leituras(FILE *arquivo_genoma, FILE *arquivo_pos_genes, FILE *arquivos_fragmentos, FILE *arquivos_pos_fragmentos, int n_genes, int n_fragmentos, FILE *atividade_genica_txt)
{
    ctrl_f(arquivo_genoma, arquivos_fragmentos, arquivos_pos_fragmentos);
    contagem_interseccoes(arquivo_pos_genes, arquivos_pos_fragmentos, n_genes, n_fragmentos, atividade_genica_txt);
}