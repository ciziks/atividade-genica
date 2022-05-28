#include <stdlib.h>
#include <stdio.h>

int ordena_digitos(int **A, int n, int posicao)
{
    int B[10], i, digito;
    for (i = 0; i < 10; i++)
        B[i] = 0;
    // calloc

    for (i = 0; i < n; i++)
    {
        digito = A[i][0] / posicao;
        digito = abs(digito) % 10;
        B[digito] = B[digito] + 1;
    }

    for (i = 1; i < 10; i++)
        B[i] = B[i] + B[i - 1];

    int C[n][2];

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
}

int ordena_numeros(int **A, int n)
{
    int maior = A[0][0], posicao = 1;

    for (int i = 0; i < n; i++)
    {
        if (A[i][0] > maior)
            maior = A[i][0];
    }

    while (maior / posicao > 0)
    {
        OrdenaDigitos(A, n, posicao);
        posicao = posicao * 10;
    }
}