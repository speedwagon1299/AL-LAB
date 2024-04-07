#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sieve(int* arr, int n)
{
    for(int i = 2; i*i < n; i++)
    {
        for(int j = i*i; j < n; j+= i)
        {
            arr[j] = 1;
        }
    }
}

void pf(int a, int* apf, int* arr, int n)
{
    int k = 0;
    for(int i = 2; i < n; i++)
    {
        if(arr[i] == 0)
        {
            while(a%i == 0 && a > 1)
            {
                a/= i;
                apf[k++] = i;
            }
            if(a == 1)
            {
                break;
            }
        }
    }
}

void comp(int* ppf, int* qpf, int* ans)
{
    int p = 0, q = 0;
    while(ppf[p] != 0 && qpf[q] != 0)
    {
        if(ppf[p] == qpf[q])
        {
            *ans *= ppf[p];
            p++; q++;
        }
        else if(ppf[p] > qpf[q])
        {
            q++;
        }
        else
        {
            p++;
        }
    }
}

int main()
{
    printf("\nEnter the value of p and q:\n");
    int p,q; scanf("%d%d",&p,&q);
    if(p < q)   swap(&p,&q);
    int* arr = (int*) calloc(p+1,sizeof(int));
    int* ppf = (int*) calloc((int)log2(p)+1,sizeof(int));
    int* qpf = (int*) calloc((int)log2(q)+1,sizeof(int));
    sieve(arr,p+1);
    pf(p,ppf,arr,p+1);
    pf(q,qpf,arr,p+1);
    printf("\n");
    int ans = 1;
    comp(ppf,qpf,&ans);
    printf("\nGCD: %d",ans);
    return 0;
}