#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int l, int r) {
    int pivot = l;
    l += 1;
    while(l <= r) {
        while(l <= r && arr[pivot] > arr[l]) {
            l++;
        }
        while(r >= l && arr[pivot] <= arr[r]) {
            r--;
        }
        swap(&arr[l],&arr[r]);
    }
    swap(&arr[l],&arr[r]);
    swap(&arr[r],&arr[pivot]);
    return r;

}

void quickSort(int l, int r, int* arr) {
    if(r - l <= 1) {
        return;
    }
    int s = partition(arr,l,r);
    quickSort(l,s,arr);
    quickSort(s+1,r,arr);
}

int main() {
    printf("\nEnter number of elements:\n");
    int n; scanf("%d",&n);
    int* arr = (int*) calloc(n,sizeof(int));
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand()%1000;
    }
    printf("\nArray:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    quickSort(0,n-1,arr);
    printf("\nSorted:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}