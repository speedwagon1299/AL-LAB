#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b; 
    *b = temp;
}

int max(int a, int b) {
    return (a>b)?a:b;
}

void top_down(int* heap, int i) {
    if(i == 1) {
        return;
    }
    if(heap[i] > heap[i/2]) {
        swap(&heap[i],&heap[i/2]);
        top_down(heap,i/2);
    }
}

void heapify(int* arr, int i, int n) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left <= n && arr[left] > arr[largest])
        largest = left;
    
    if(right <= n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, largest, n);
    }
}

void bottom_up(int* arr, int n) {
    for(int i = n/2; i >= 1; i--) {
        heapify(arr,i,n);
    }
}

int main() {
    int arr[7] = {0,2,9,7,6,5,8};
    int* heap = (int*) calloc(7,sizeof(int));
    for(int i = 1; i <= 6; i++) {
        heap[i] = arr[i];
        top_down(heap,i);
    }
    printf("\nTop Down:\n");
    for(int i = 1; i <= 6; i++) {
        printf("%d, ",heap[i]);
    }    
    printf("\nBottom Up:\n");
    bottom_up(arr,6);
    for(int i = 1; i <= 6; i++) {
        printf("%d, ",arr[i]);
    }
    printf("\nHeap Sort:\n");
    for(int i = 6; i >= 1; i--) {
        swap(&arr[1],&arr[i]);
        heapify(arr,1,i-1);
    }
    for(int i = 1; i <= 6; i++) {
        printf("%d, ",arr[i]);
    }
    return 0;
}