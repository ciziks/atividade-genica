#include <stdlib.h>
#include <stdio.h>

void ContagemLeituras(FILE *arquivo_genoma, FILE *arquivo_pos_genes, FILE *arquivos_fragmentos, FILE *arquivos_pos_fragmentos, int n_genes, int n_fragmentos, FILE *atividade_genica_txt)
{
    CtrlF(arquivo_genoma, arquivos_fragmentos, arquivos_pos_fragmentos);
    ContagemIntersecoes(arquivo_pos_genes, arquivos_pos_fragmentos, n_genes, n_fragmentos, atividade_genica_txt);
}