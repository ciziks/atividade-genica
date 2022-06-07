#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arquivos.h"
#include "ordenacao.h"

// Lê uma linha do arquivo fornecido
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
    if (linha != NULL) {
      linha = (char *)realloc(linha, (qtd_letras + 1) * sizeof(char));
      linha[qtd_letras] = '\0';
    }

    return linha;
}

// Conta o número de intersecções entre intervalos de dois arquivos
void contagem_interseccoes(FILE *arquivo_A, FILE *arquivo_B, long nA, long nB, FILE *arquivo_contagens)
{
    long **A = (long **)malloc(sizeof(long *)* nA);
    long **B = (long **)malloc(sizeof(long *)* nB);
    long *contagens = (long*)malloc(sizeof(long)* nA);

    for (long i = 0; i < nA; i++)
        A[i] = (long *)malloc(sizeof(long)*2);

    for (long i = 0; i < nB; i++)
        B[i] = (long *)malloc(sizeof(long)*2);

    for (long i = 0; i < nA; i++)
        contagens[i] = 0;

    // Lê Intervalos de A
    for (long i = 0; i < nA; i++)
    {
        A[i][0] = atol(ler_linha(arquivo_A, ','));
        A[i][1] = atol(ler_linha(arquivo_A, '\n'));
    }

    fseek(arquivo_B,0,SEEK_SET);

    for (long i = 0; i < nB; i++)
    {
        B[i][0] = atol(ler_linha(arquivo_B, ','));
        B[i][1] = atol(ler_linha(arquivo_B, '\n'));
    }

    // Ordenando Intervalos de A
    ordena_numeros(A, nA);

    // Ordenando Intervalos de B
    ordena_numeros(B, nB);

    long primeiro_iB = 0;
    for (long iA = 0; iA < nA; iA++)
    {
        for (long iB = primeiro_iB; iB < nB; iB++)
        {
            // Verificando se não houve intersecção entre os intervalos
            if (A[iA][1] < B[iB][0] || A[iA][0] > B[iB][1])
            {
                // Como os intervalos estão ordenados, podemos descartar um intervalo que não possui intersecção com o atual, nos próximos
                if (!contagens[iA])
                    primeiro_iB = iB;
            }
            else
                contagens[iA]++; // Ocorreu Intersecção
        }
    }

    // Inserindo Contagens encontradas no Arquivo txt
    for (long i = 0; i < nA; i++)
        fprintf(arquivo_contagens, "%ld\n", contagens[i]);

    for (long i = 0; i < nA; i++)
    {
        free(A[i]);
    }
    for (long i = 0; i < nB; i++)
    {   
        free(B[i]);
    }

    free(A);
    free(B);
    free(contagens);
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
