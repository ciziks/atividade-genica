#include <stdlib.h>
#include <stdio.h>

int OrdenaDigitos(int A[][2], int n, int posicao)
{
    int B[10], i, digito;
    for(i=0;i<10;i++)
        B[i] = 0;
        //calloc
    
    for(i=0; i<n; i++)
    {
        digito = A[i][0]/posicao;
        digito = digito % 10;
        B[digito] = B[digito] + 1;
    }

    for(i=1;i<10;i++)
        B[i] = B[i] + B[i-1];
    
    int C[n][2];

    for(i=n-1; i>=0; i--)
    {
        digito = A[i][0]/posicao;
        digito = digito % 10;
        B[digito] = B[digito] - 1;
        C[B[digito]][0] = A[i][0];
        C[B[digito]][1] = A[i][1];

    }

    for(i=0; i<n; i++)
    {
        A[i][0] = C[i][0];
        A[i][1] = C[i][1];
    }
}

int OrdenaNumeros(int A[][2], int n)
{
    int maior = A[0][0], posicao = 1;

    for(int i = 0; i < n; i++)
    {
        if(A[i][0] > maior)
            maior = A[i][0];
    }

    while(maior/posicao > 0)
    {
        OrdenaDigitos(A, n, posicao);
        posicao = posicao * 10;
    }
}

void ContagemIntersecoes(FILE *A_txt, FILE *B_txt, int nA, int nB, FILE *contagens_txt)
{
    int A[nA][2], B[nB][2], contagens[nA];

    for(int i = 0;i < nA; i++)
        contagens[i] = 0;
        //calloc

    char c, aux;
    for(int i = 0; i < nA; i++)
    {
        c = fgetc(A_txt);
        A[i][0] = c;
        while(1)
        {
            c = fgetc(A_txt);
            if(c != '\n' || c != '\0')
                aux = c;
            else
            {
                A[i][1] = aux;
                break;
            }       
        }
    }

    for(int i = 0; i < nB; i++)
    {
        c = fgetc(B_txt);
        B[i][0] = c;
        while(1)
        {
            c = fgetc(B_txt);
            if(c != '\n')
                aux = c;
            else
            {
                B[i][1] = aux;
                break;
            }       
        } 
    }

    OrdenaNumeros(A, nA);
    OrdenaNumeros(B, nB);

    int primeiro_iB = 0;
    for(int iA = 0; iA < nA; iA++)
    {
        for(int iB = primeiro_iB; iB < nB; iB++)
        {
            if(A[iA][1] < B[iB][0] || A[iA][0] > B[iB][1])
            {
                if(contagens[iA] == 0)
                    primeiro_iB = iB;
            }
            else
            {
                contagens[iA] = contagens[iA] + 1;
            }
        }
    }
    for(int i = 0; i < nA; i++)
        fprintf(contagens_txt, "%d\n", contagens[i]);
}

void CtrlF(FILE *arq_txt, FILE *arq_trechos, FILE *arq_saida)
{
    char trecho[50];
    char texto[50]; // Ler arquivo arq_txt todo
    int i, j;
    while(fgets(trecho, 50, arq_trechos) != NULL)
    {
        i = 0;
        while(texto[i] != '\n' || texto[i] != '\0')
        {
            j = 0;

            while((trecho[j] != '\n' || trecho[j] != '\0') && texto[i+j] == trecho[j])
            {
                j++;
            }

            if(trecho[j] == '\n' || trecho[j] == '\0')
            {
                fprintf(arq_saida, "%d, %d", i, i+j-1);
                break;
            }

            i++;
        }
    }
}