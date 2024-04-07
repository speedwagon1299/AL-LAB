#include <stdio.h>
#include <stdlib.h>

    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(int left, int right, int* arr)
    {
        int pivot = arr[left];
        int l = left+1, r = right;
        while(l <= r)
        {
            while(l <= r && arr[l] <= pivot) l++;
            while(r >= l && arr[r] > pivot) r--;
            swap(&arr[l],&arr[r]);
        }
        swap(&arr[l],&arr[r]);
        swap(&arr[r],&arr[left]);
        return r;
    }

    void quickSort(int left, int right, int* arr)
    {
        if(right - left <= 1)
        {
            return;
        }
        int s = partition(left,right,arr);
        quickSort(left,s-1,arr);
        quickSort(s+1,right,arr);
    }

void binSearch(int low, int high, int* arr, int search)
{
    if(low > high)
    {
        printf("-1");;
        return;
    }
    int mid = low + (high-low)/2;
    if(arr[mid] == search)
    {
        printf("%d",mid);
        return;
    }
    else if(arr[mid] < search)
    {
        binSearch(mid+1,high,arr,search);
    }
    else
    {
        binSearch(low,mid-1,arr,search);
    }
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
    quickSort(0,n-1,arr);
    printf("\nSorted:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    binSearch(0,n-1,arr,arr[4]);
}