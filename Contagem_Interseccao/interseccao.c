#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arquivo.h"
#include "interseccao.h"
#include "ordenacao.h"

// Conta o número de intersecções entre intervalos de dois arquivos
void contagem_interseccoes(FILE *arquivo_A, FILE *arquivo_B, long nA, long nB, FILE *arquivo_contagens)
{
    long **A = (long **)malloc(sizeof(long *) * nA);
    long **B = (long **)malloc(sizeof(long *) * nB);
    long *contagens = (long *)malloc(sizeof(long) * nA);

    for (long i = 0; i < nA; i++)
        A[i] = (long *)malloc(sizeof(long) * 2);

    for (long i = 0; i < nB; i++)
        B[i] = (long *)malloc(sizeof(long) * 2);

    for (long i = 0; i < nA; i++)
        contagens[i] = 0;
   
    // Lê Intervalos de A
    char *aux;
    for (long i = 0; i < nA; i++)
    {
        aux = ler_linha(arquivo_A, ',');
        A[i][0] = atol(aux);
        free(aux);
        aux = ler_linha(arquivo_A, '\n');
        A[i][1] = atol(aux);
        free(aux);
    }

    //Redireciona o ponteiro interno do arquivo para o inicio novamente
    fseek(arquivo_B, 0, SEEK_SET);

    // Lê Intervalos de B
    for (long i = 0; i < nB; i++)
    {
        //Caso a quantidade de pos-fragmentos encontrados forem menores que os fragmentos esperados repassa o tamanho do vetor nB
        aux = ler_linha(arquivo_B, ',');
        if(aux == NULL)
        {
            nB = i;
            break;
        }
        B[i][0] = atol(aux);
        free(aux);
        aux = ler_linha(arquivo_B, '\n');
        B[i][1] = atol(aux);
        free(aux);
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