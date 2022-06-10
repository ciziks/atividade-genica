#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arquivo.h"
#include "ordenacao.h"

// Lê uma linha do arquivo fornecido, encerrando no delimitar passado como parametro, como "," ou "\n"
char *ler_linha(FILE *arquivo, char delimitador)
{
    int qtd_letras = 0;
    char *linha = NULL;
    char letra = fgetc(arquivo);

    while (letra != delimitador && letra != EOF)
    {
        linha = (char *)realloc(linha, ++qtd_letras * sizeof(char));
        linha[qtd_letras - 1] = letra;
        letra = fgetc(arquivo);
    }
    if (linha != NULL || letra == '\n')
    {
        linha = (char *)realloc(linha, (qtd_letras + 1) * sizeof(char));
        linha[qtd_letras] = '\0';
    }

    return linha;
}

// Encontra a posição de início e fim (intervalo) da primeira ocorrência de um trecho no texto
void ctrl_f(FILE *arquivo_texto, FILE *arquivo_trechos, FILE *arquivo_saida)
{
    // Lendo arquivo texto
    char *texto = ler_linha(arquivo_texto, '\0');
    char *trecho;
    long i, j;

    while ((trecho = ler_linha(arquivo_trechos, '\n')) != NULL)
    {
        i = 0;
        while (texto[i] != '\0')
        {
            j = 0;

            while (trecho[j] != '\0' && texto[i + j] == trecho[j])
                j++;

            if (trecho[j] == '\0')
            {
                fprintf(arquivo_saida, "%ld,%ld\n", i, i + j - 1);
                break;
            }

            i++;
        }
        free(trecho);
    }
    free(texto);
}
