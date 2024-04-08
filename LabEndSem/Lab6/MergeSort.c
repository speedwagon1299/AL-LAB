#include <stdio.h>
#include <stdlib.h>

int count = 0;

void printinv(int* arr, int p1, int p2, int mid) {
    for(int i = p1; i <= mid; i++) {
        printf("(%d,%d), ",arr[i],arr[p2]);
        count++;
    }
}

void merge(int l, int mid, int r, int* arr) {
    int* temp = (int*) calloc(r-l+1,sizeof(int));
    int p1 = l, p2 = mid+1, k = 0;
    while(p1 <= mid && p2 <= r) {
        if(arr[p1] <= arr[p2]) {
            temp[k++] = arr[p1++];
        }
        else {
            printinv(arr,p1,p2,mid);
            temp[k++] = arr[p2++];
        }
    }
    while(p1 <= mid) {
        temp[k++] = arr[p1++];
    }
    while(p2 <= r) {
        temp[k++] = arr[p2++];
    }
    for(int i = l; i <= r; i++) {
        arr[i] = temp[i-l];
    }
    free(temp);
}

void mergeSort(int l, int r, int* arr) {
    if(r <= l) {
        return;
    }
    int mid = l + (r-l)/2;
    mergeSort(l,mid,arr);
    mergeSort(mid+1,r,arr);
    merge(l,mid,r,arr);
}

int main()
{
    printf("\nEnter number of elements:\n");
    int n; scanf("%d",&n);
    int* arr = (int*) calloc(n,sizeof(int));
    printf("\nEnter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    mergeSort(0,n-1,arr);
    printf("\nNumber of Inversions: %d",count);
    printf("\nSorted:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}