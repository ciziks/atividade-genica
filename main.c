#include <stdlib.h>
#include <stdio.h>
#include "leitura.h"
#include <string.h>

int contar_linhas(FILE * fp);

int main(int argc, char const *argv[])
{
    if (argc < 4) {
      printf("Uso: ./exec <arquivo_genoma> <arquivo_posicao_genes> <arquivo_fragmentos>\n\n");
      printf("Exemplo: ./exec genoma_pequeno.txt pos_genes_pequeno.csv fragmentos_pequeno.txt\n");
      return 0;
    }
    char str[100];
    strcpy(str,"./Entrada/");
    strcat(str, argv[1]);
    FILE *genoma = fopen(str, "r");
    strcpy(str,"./Entrada/");
    strcat(str, argv[2]);
    FILE *pos_genes = fopen(str, "r");
    strcpy(str,"./Entrada/");
    strcat(str, argv[3]);
    FILE *fragmentos = fopen(str, "r");

    FILE *atividade_genica = fopen("./Saida/atividade_genica.txt", "w");
    FILE *pos_fragmentos = fopen("./Saida/pos_fragmentos.csv", "w+");

    contagem_leituras(genoma, pos_genes, fragmentos, pos_fragmentos, contar_linhas(pos_genes), contar_linhas(fragmentos), atividade_genica);

    fclose(atividade_genica);
    fclose(pos_fragmentos);
    fclose(genoma);
    fclose(pos_genes);
    fclose(fragmentos);

    return 0;
}

int contar_linhas(FILE * fp){
  int linhas = 0;
  char ch;
  while(!feof(fp)){
    ch = fgetc(fp);
    if(ch == '\n'){
      linhas++;
    }
  }
  fseek(fp, 0, SEEK_SET);
  return linhas;
}
