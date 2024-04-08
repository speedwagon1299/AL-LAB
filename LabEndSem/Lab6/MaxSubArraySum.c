#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int max(int a, int b) {
    return (a>b)?a:b;
}

int maxsubsum(int* arr, int l, int r) {
    if(l == r) {
        return arr[l];
    }
    int mid = l + (r-l)/2;
    int left = maxsubsum(arr,l,mid);
    int right = maxsubsum(arr,mid+1,r);
    int leftmax = INT_MIN, rightmax = INT_MIN, runsum = 0;
    for(int i = mid; i >= l; i--) {
        runsum += arr[i];
        leftmax = max(leftmax,runsum);
    }
    runsum = 0;
    for(int i = mid; i <= r; i++) {
        runsum += arr[i];
        rightmax = max(rightmax,runsum);
    }
    int midsum = max(max(leftmax,rightmax),leftmax+rightmax-arr[mid]);
    return max(max(left,right),midsum);
}

int main() {
    printf("\nEnter the number of elements:\n");
    int n; scanf("%d",&n);
    int* arr = (int*) calloc(n,sizeof(int));
    printf("\nEnter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("\nMax Subarray Sum:\t%d",maxsubsum(arr,0,n));
}