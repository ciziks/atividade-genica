#include <stdlib.h>
#include <stdio.h>

#include "leitura.h"
#include "intersecao.h"
#include "ctrl_f.h"

// Contagem de fragmentos por gene 
void contagem_leituras(FILE *arquivo_genoma, FILE *arquivo_pos_genes, FILE *arquivos_fragmentos, FILE *arquivos_pos_fragmentos, long n_genes, long n_fragmentos, FILE *atividade_genica_txt)
{
    // Encontra o intervalo de cada fragmento de mRNA no Genoma
    ctrl_f(arquivo_genoma, arquivos_fragmentos, arquivos_pos_fragmentos);

    // Contagem das intersecções entre os fragmentos de mRNA e os Genes (intervalos do Genoma)
    contagem_intersecoes(arquivo_pos_genes, arquivos_pos_fragmentos, n_genes, n_fragmentos, atividade_genica_txt);
}
