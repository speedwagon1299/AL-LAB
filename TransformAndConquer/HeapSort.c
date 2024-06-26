#include <stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i) {
	// Find largest
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest])
	    largest = left;
	if (right < n && arr[right] > arr[largest])
	    largest = right;
	// Swap and continue heapifying if root is not largest
	if (largest != i) {
	    swap(&arr[i], &arr[largest]);
	    heapify(arr, n, largest);
	    }
}

void heapSort(int arr[], int n) {
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--)
	    heapify(arr, n, i);
	// Heap sort
	for (int i = n - 1; i >= 0; i--) {
	    swap(&arr[0], &arr[i]);
	    // Heapify root element to get highest element at root again
	    heapify(arr, i, 0);
	}
}

void display(int arr[], int n) {
	for (int i = 0; i < n; ++i)
	    printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int n;
	printf("Enter n:");
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
	    printf("Enter element %d: ", i);
	    scanf("%d", &arr[i]);
	}
	printf("Original array: \n");
	for(int i=0;i<n;i++){
	    printf("%d ", arr[i]);
	}
	heapSort(arr, n);
	printf("\nHeapsort: \n");
	display(arr, n);
}