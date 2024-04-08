#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b) {
    return (a>b)?a:b;
}

void sieve(int* arr, int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        for(int j = i*i; j <= n; j++) {  //try <=
             arr[j] = 1;
        }
    }
}

void pf(int* apf, int a, int* arr, int n) {
    int k = 0;
    for(int i = 2; i <= n; i++) {
        if(arr[i] == 0) {
            while(a%i == 0 && a > 1) {
                a/= i;
                apf[k++] = i;
            }
            if(a == 1) {
                return;
            }
        }
    }
}

int compute(int* apf, int* bpf)
{
    int a = 0, b = 0, ans = 1;
    while(apf[a] != 0 && apf[b] != 0) {
        if(apf[a] == bpf[b]) {
            ans*= apf[a];
            a++; b++;
        }
        else if(apf[a] < bpf[b]) {
            a++;
        }
        else {
            b++;
        }
    }
    return ans;
}

int main() {
    printf("\nEnter the two numbers:\n");
    int a, b; scanf("%d%d",&a,&b);
    int prime_len = max(a,b) + 1;
    int* arr  = (int*) calloc(prime_len,sizeof(int));
    sieve(arr,prime_len);
    int* a_pri = (int*) calloc(log2(a)+1,sizeof(int));
    int* b_pri = (int*) calloc(log2(b)+1,sizeof(int));
    pf(a_pri,a,arr,prime_len);
    pf(b_pri,b,arr,prime_len);
    printf("\nGCD: %d",compute(a_pri,b_pri));
}