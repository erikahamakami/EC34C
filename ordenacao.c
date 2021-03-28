#include <stdio.h>
#include <stdlib.h>

void insertion (int *A);
void selection (int *A, int n);

int main(int argc, char* argv[])
{
    int *A =  malloc(sizeof(int)*10);
    int i = 0;

    for(i = 0; i < 10; i++){
        A[i] = 10 - i;
    }

    for (i = 0; i < 10; i++)
    {
        printf("Insira um valor: ");
	    scanf("%d", &A[i]);
    }

    printf("\nValores inseridos: ");
    for(i = 0; i < 10; i++){
        printf("%d ", A[i]);
    }

    // insertion(A);
    selection(A, 10);

    printf("\nValores ordenados: ");

    for (i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
    free(A);

    
    return 0;
}

void insertion (int *A, int n) 
{
        int i, j, x;

    for (int j = 1; j < n; j++){
        x = A[j];
        for (i = j-1; i>=0 && A[i]>=x; i--) {
            A[i+1] = A[i];
        }
        A[i+1] = x;        
    }
}

void selection (int *A, int n) 
{ 
    int i, j, aux, m;

    for (j = 0; j < n-1; j++){
        m = j;
        for (i = j+1; i < n; i++){
            if (A[i] < A[m]){
                m = i;
            }
        }
        aux = A[j];
        A[j] = A[m];
        A[m] = aux;
    }
} 