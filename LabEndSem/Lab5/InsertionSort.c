#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void insertionSort(int* arr, int n) {
    int temp;
    int j;
    for(int i = 1; i < n; i++) {
        j = i-1;
        temp = arr[i];
        while(j >= 0 && temp < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main() {
    printf("\nEnter the number of elements:\n");
    int n; scanf("%d",&n);
    int* arr = (int*) calloc(n,sizeof(int));
    printf("\nEnter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
    for(int i = 0; i < n; i++) {
        printf("%d, ",arr[i]);
    }
}