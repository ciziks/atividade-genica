#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"

long ordena_digitos(long **A, long n_linhas, long posicao)
{
    long i, digito;

    // Inicializando B com zeros
    long *B = (long *)calloc(10, sizeof(long));

    // Contagem da quantidade de algarismos (0, 1, ..., 9) dentre todos elementos
    // no dígito, da direita à esquerda, log(posicao)
    for (i = 0; i < n_linhas; i++)
    {
        digito = A[i][0] / posicao;
        digito = digito % 10;
        B[digito]++;
    }

    for (i = 1; i < 10; i++)
        B[i] += B[i - 1];

    // Inicializando matriz C com n linhas e 2 colunas
    long **C = (long **)malloc(n_linhas * sizeof(long *));

    for (i = 0; i < n_linhas; i++)
        C[i] = (long *)malloc(2 * sizeof(long));

    // Ordenando elementos com base no algarismo
    // e inserindo em C
    for (i = n_linhas - 1; i >= 0; i--)
    {
        digito = A[i][0] / posicao;
        digito = digito % 10;
        B[digito]--;
        
        C[B[digito]][0] = A[i][0];
        C[B[digito]][1] = A[i][1];
    }

    // Repassando ordenação para a matriz original
    for (i = 0; i < n_linhas; i++)
    {
        A[i][0] = C[i][0];
        A[i][1] = C[i][1];
    }

    // Desalocando memória
    for (i = 0; i < n_linhas; i++)
        free(C[i]);

    free(C);
    free(B);
}

// Algoritmo baseado na ordenação dos dígitos
long ordena_numeros(long **A, long n)
{
    long maior = A[0][0], posicao = 1;

    // Encontrando maior número
    for (long i = 0; i < n; i++)
    {
        if (A[i][0] > maior)
            maior = A[i][0];
    }

    // Ordenando dígitos M vezes
    // onde M é o número de dígitos do maior elemento
    while (maior / posicao > 0)
    {
        ordena_digitos(A, n, posicao);
        posicao *= 10; // Próximo Dígito
    }
}