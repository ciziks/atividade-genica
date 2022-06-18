#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ctrl_f.h"
#include "intersecao.h"
#include "ordenacao.h"

// Conta o número de intersecções entre dois intervalos
void contagem_intersecoes(FILE *arquivo_A, FILE *arquivo_B, long nA, long nB, FILE *arquivo_contagens)
{
    // Inicializando Matrizes com seu respectivo tamanho de linhas
    long **A = (long **)malloc(sizeof(long *) * nA);

    for (long i = 0; i < nA; i++)
        A[i] = (long *)malloc(2 * sizeof(long));

    long **B = (long **)malloc(sizeof(long *) * nB);

    for (long i = 0; i < nB; i++)
        B[i] = (long *)malloc(2 * sizeof(long));

    // Vetor das contagens de Intersecções de cada intervalo de A
    long *contagens = (long *)calloc(nA, sizeof(long));

    // Lê e armazena intervalos de A
    char *extremo;
    for (long i = 0; i < nA; i++)
    {
        extremo = ler_linha(arquivo_A, ',');
        A[i][0] = atol(extremo);
        free(extremo);

        extremo = ler_linha(arquivo_A, '\n');
        A[i][1] = atol(extremo);
        free(extremo);
    }

    // Lê e armazena intervalos de B
    for (long i = 0; i < nB; i++)
    {
        extremo = ler_linha(arquivo_B, ',');
        B[i][0] = atol(extremo);
        free(extremo);

        extremo = ler_linha(arquivo_B, '\n');
        B[i][1] = atol(extremo);
        free(extremo);
    }

    // Ordenando intervalos de A
    ordena_numeros(A, nA);

    // Ordenando intervalos de B
    ordena_numeros(B, nB);

    long primeiro_iB = 0;
    for (long iA = 0; iA < nA; iA++)
    {
        for (long iB = primeiro_iB; iB < nB; iB++)
        {
            // Verificando se não houve intersecção entre os intervalos
            if (A[iA][1] < B[iB][0] || A[iA][0] > B[iB][1])
            {
                // Como os intervalos estão ordenados, podemos descartar um intervalo que não possui intersecção com o atual para os próximos
                if (!contagens[iA])
                    primeiro_iB = iB;
            }
            else
                contagens[iA]++; // Ocorreu Intersecção
        }
    }

    // Inserindo contagens calculadas no arquivo de saída
    for (long i = 0; i < nA; i++)
        fprintf(arquivo_contagens, "%ld\n", contagens[i]);

    // Desalocando Memória
    for (long i = 0; i < nA; i++)
        free(A[i]);
    for (long i = 0; i < nB; i++)
        free(B[i]);

    free(A);
    free(B);
    free(contagens);
}
