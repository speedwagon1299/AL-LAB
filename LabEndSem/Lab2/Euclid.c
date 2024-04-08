#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int gcd(int p, int q) {
    if(q == 0) {
        return p;
    }
    return gcd(q,p%q);
}

int main() {
    printf("\nEnter the two numbers:\n");
    int a, b; scanf("%d%d",&a,&b);
    if (a < b) {
        swap(&a,&b);
    }
    int c = gcd(a,b);
    printf("\nGCD: %d",c);
    return 0;
}