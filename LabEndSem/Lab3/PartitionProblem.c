#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void partition(int* arr, int n) {
    int temp, sum1, sum0, ind, k0, k1;
    for(int i = 1; i < pow(2,n); i++) {
        temp = i;
        sum1 = sum0 = 0;
        ind = k0 = k1 = 0;
        int* arr0 = (int*) calloc(n,sizeof(int)); 
        int* arr1 = (int*) calloc(n,sizeof(int)); 
        for(int j = 1; j <= n; j++) {
            if(temp%2 == 1) {
                sum1 += arr[ind]; 
                arr0[k0++] = arr[ind];
            }
            else {
                sum0 += arr[ind];
                arr1[k1++] = arr[ind];
            }
            temp >>= 1;
            ind++;
        }
        if(sum0 == sum1) {
            ind = 0;
            printf("\nSet 0:\n");
            while(arr0[ind] != 0) {
                printf("%d, ",arr0[ind++]);
            }
            ind = 0;
            printf("\nSet 1:\n");
            while(arr1[ind] != 0) {
                printf("%d, ",arr1[ind++]);
            }
            return;
        }
        free(arr0);
        free(arr1);
    }
    printf("\nNo sets found");
}

int main() {
    printf("\nEnter the number of elements:\n");
    int n; scanf("%d",&n);
    int* arr = (int*) calloc(n,sizeof(int));
    printf("\nEnter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    partition(arr,n);
    return 0;
}