#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void merge (int *a, int inicio, int meio, int fim) {
int i, j, k;
int n1 = meio - inicio + 1;
int n2 = fim - meio;
int vEsq [ n1 ], vDir [ n2 ];

for ( i = 0; i < n1; i++)
{
    vEsq[ i ] = a[ inicio + i ];
}

for ( j = 0; j < n2 ; j++)
{
    vDir[ j ] =a[ meio + 1 + j ];
}

i = 0;
j = 0;
k = inicio;

while (i < n1 && j < n2)
{
    if ( vEsq [ i ] < vDir [ j ])
    {
        a[ k ] = vEsq [ i ];
        i++;

    }else
    {
        a[ k ] = vDir [ j ];
        j++;
    }
    k++;
}

while ( i < n1 )
{
    a [ k ] = vEsq [ i ];
    i++;
    k++;
}

while ( j < n2 )
{
    a[ k ] = vDir [ j ];
    j++;
    k++;
}

}

void mergesort (int *a, int inicio, int fim)
{
if ( inicio < fim )
{
    int meio = inicio + ( fim - inicio )/2;
    mergesort ( a, inicio, meio);
    mergesort (a, meio+1, fim);
    merge (a, inicio, meio, fim);
}
}

int main (){
    int tam = 10, nums [ tam ], k,n = 0;

    for (int i = 0; i < tam; i++)
    {
        nums[i] = rand() % 101;
    }
    
   /*
    nums[0] = -1;
    nums[1] = -2;
    nums[2] = 3;
    nums[3] = 4;
    k = 3
    */

    /*
    nums[0] = 2;
    nums[1] = 1;
    nums[2] = 3;
    nums[3] = 3;
    k = 2
    */

    /*
    nums[0] = 3;
    nums[1] = 4;
    nums[2] = 3;
    nums[3] = 3;
    k = 2
    */

    printf("informe o numero de elementos para soma:");
    scanf("%d", &k);
    int result[k], pos[k];
    int copia[tam];

    for (int i = 0; i < tam; i++)
    {
        copia [i] = nums [i];
    }
    
    mergesort(copia,0,tam-1);
    
    
    for (int i=tam -k; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (copia[i] == nums[j])
            {
                pos[n] = j; //pos terá as posições dos maiores numeros do vetor
                n++;
                break;
            }
        }
    }
    
    mergesort(pos,0,k-1);
        
        for (int i = 0; i < k; i++)
        {
            result[i] = nums[pos[i]];
        }
        printf("\n");
        for (int i = 0; i < k; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
}
