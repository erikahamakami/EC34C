#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion (int *A, int tamanho);
void selection (int *A, int tamanho);

int main(int argc, char* argv[])
{
    int *A;
    int k, i = 0;
    int tamanho = 1000;
    clock_t start, end;
    double tempo_cpu_usado;

    for (k = 0; k <= 7; k++){
        A =  malloc(sizeof(int) * tamanho);

        for(i = 0; i < tamanho; i++){
            A[i] = i;
        }
        
        start = clock();
        selection (A, tamanho);
        end = clock();
        tempo_cpu_usado = ((double)(end - start))/CLOCKS_PER_SEC;
        printf("Selection \t\t %d\t %lf \n", tamanho, tempo_cpu_usado);

        start = clock();
        insertion (A, tamanho);
        end = clock();
        tempo_cpu_usado = ((double)(end - start))/CLOCKS_PER_SEC;
        printf("Insertion Melhor \t %d\t %lf \n", tamanho, tempo_cpu_usado);

        for (i=0; i < tamanho; i++){
            A[i] = tamanho - i;
        }

        start = clock();
        insertion (A, tamanho);
        end = clock();
        tempo_cpu_usado = ((double)(end - start))/CLOCKS_PER_SEC;
        printf("Insertion Pior \t\t %d\t %lf \n\n", tamanho, tempo_cpu_usado);

        tamanho = tamanho * 2;
        free(A);
    }
    return 0;
}

void insertion (int *A, int tamanho) 
{
    int i, j, x;

    for (int j = 1; j < tamanho; j++){
        x = A[j];
        for (i = j-1; i>=0 && A[i]>=x; i--) {
            A[i+1] = A[i];
        }
        A[i+1] = x;        
    }
}

void selection (int *A, int tamanho) 
{ 
    int i, j, aux, m;

    for (j = 0; j < tamanho-1; j++){
        m = j;
        for (i = j+1; i < tamanho; i++){
            if (A[i] < A[m]){
                m = i;
            }
        }
        aux = A[j];
        A[j] = A[m];
        A[m] = aux;
    }
} 