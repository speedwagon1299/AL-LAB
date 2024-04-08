#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int expcalc(int a, int b) {
    if(b == 1) { 
        return a;
    }
    if(b%2 == 0) {
        return expcalc(a*a,b/2);
    }
    else {
        return a*expcalc(a*a,b/2);
    }
}

int main() {
    printf("\nEnter a and n:\n");
    int n,a; scanf("%d%d",&a,&n);
    printf("%d",expcalc(a,n));
}