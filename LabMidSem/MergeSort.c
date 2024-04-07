#include <stdio.h>
#include <stdlib.h>

void merge(int low, int mid, int high, int* arr)
{
    int* temp = (int*) calloc(high-low+1,sizeof(int));
    int p1 = low, p2 = mid+1, i = 0;
    while(p1 <= mid && p2 <= high)
    {
        while(arr[p1] <= arr[p2] && p1 <= mid)
        {
            temp[i++] = arr[p1++];
        }
        while(arr[p2] <= arr[p1] && p2 <= high)
        {
            temp[i++] = arr[p2++];
        }
    }
    while(p1 <= mid)
    {
        temp[i++] = arr[p1++];
    }
    while(p2 <= high)
    {
        temp[i++] = arr[p2++];
    }
    for(i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    free(temp);
}

void mergeSort(int low, int high, int* arr)
{
    if(low >= high)
    {
        return;
    }
    int mid = low + (high-low)/2;
    mergeSort(low,mid,arr);
    mergeSort(mid+1,high,arr);
    merge(low,mid,high,arr);
}

int main()
{
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
    mergeSort(0,n-1,arr);
    printf("\nSorted:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}