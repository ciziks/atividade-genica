#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"

long ordena_digitos(long **A, long n, long posicao)
{
    long i, digito;
    long *B = (long *)calloc(10, sizeof(long));


    for (i = 0; i < n; i++)
    {
        digito = A[i][0] / posicao;
        digito = abs(digito) % 10;
        B[digito] = B[digito] + 1;
    }

    for (i = 1; i < 10; i++)
        B[i] = B[i] + B[i - 1];

    long **C = (long **)malloc(n*sizeof(long*));
    for(i = 0; i < n; i++)
    {
        C[i] = (long *)malloc(2*sizeof(long));
    }

    for (i = n - 1; i >= 0; i--)
    {
        digito = A[i][0] / posicao;
        digito = abs(digito) % 10;
        B[digito] = B[digito] - 1;
        C[B[digito]][0] = A[i][0];
        C[B[digito]][1] = A[i][1];
    }

    for (i = 0; i < n; i++)
    {
        A[i][0] = C[i][0];
        A[i][1] = C[i][1];
    }

    for(i = 0; i < n; i++)
        free(C[i]);

    free(C);
    free(B);
    
}


// TODO: Análise Teórica da Complexidade Assinótica (2)
// TODO: Estimar pior, melhor e médio casos (2)
// TODO: Explicação da Ordenação (4)
// TODO: Análise Empírica da ordenação (5)
long ordena_numeros(long **A, long n)
{
    long maior = A[0][0], posicao = 1;

    for (long i = 0; i < n; i++)
    {
        if (A[i][0] > maior)
            maior = A[i][0];
    }

    while (maior / posicao > 0)
    {
        ordena_digitos(A, n, posicao);
        posicao = posicao * 10;
    }
}