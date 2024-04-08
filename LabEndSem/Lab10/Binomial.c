#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main() {
    printf("\nEnter value of n:\n");
    int n; scanf("%d",&n);
    int* prev = (int*) calloc(n+1,sizeof(int));
    int* cur = (int*) calloc(n+1,sizeof(int));
    int* temp;
    prev[0] = 1;    prev[1] = 1;
    printf("1,\n1, 1,\n");
    for(int i = 2; i <= n; i++) {
        cur[0] = 1;
        for(int j = 1; j <= i; j++) {
            cur[j] = prev[j] + prev[j-1];
        }
        temp = cur; 
        cur = prev;
        prev = temp;
        for(int j = 0; j <= i; j++) {
        printf("%d, ",prev[j]);
        }
        printf("\n");
    }
    return 0;
}