#include <stdio.h>
#include <stdlib.h>

void compSort(int* arr, int n) {
    int* count = (int*) calloc(n,sizeof(int));
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] < arr[j]) {
                count[j]++;
            }
            else {
                count[i]++;
            }
        }
    }
    int* ans = (int*) calloc(n,sizeof(int));
    for(int i = 0; i < n; i++) {
        ans[count[i]] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        printf("%d, ",ans[i]);
    }
    free(ans);
    free(count);
}

void distribCount(int* arr, int l, int u, int n) {
    int* dis = (int*) calloc(u-l+1,sizeof(int));
    for(int i = 0; i < n; i++) {
        dis[arr[i]-l]++;
    }
    for(int i = 1; i <= u-l; i++) {
        dis[i] += dis[i-1];
    }
    int* ans = (int*) calloc(n,sizeof(int));
    for(int i = n-1; i >= 0; i--) {
        int j = arr[i]-l;
        ans[dis[j]-1] = arr[i];
        dis[j]--;
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
    compSort(arr,n);
    return 0;
}