#include <stdio.h>
#include <stdlib.h>

int _swap_temp;
#define swap(a, b) (_swap_temp=(a), (a)=(b), (b)=_swap_temp)


int arr[100];
int n;

int max(int a, int b){
    return a > b ? a : b;
}

void sift_down(int i) {
    if(i*2 < n) {
        if(i*2+1 < n) {
            int mx = max(arr[i], max(arr[i*2], arr[i*2+1]));
            if(mx == arr[i*2]) {
                swap(arr[i], arr[i*2]);
                sift_down(i*2);
            }
            else if(mx == arr[i*2+1]) {
                swap(arr[i], arr[i*2+1]);
                sift_down(i*2+1);
            }
        }
        else {
            int mx = max(arr[i], arr[i*2]);
            if(mx == arr[i*2]) {
                swap(arr[i], arr[i*2]);
                sift_down(i*2);
            }
        }
    }
}

void bubble_up(int i) {
    if(i==1)
        return;
    if(arr[i] > arr[i/2]) {
        swap(arr[i], arr[i/2]);
        bubble_up(i/2);
    }
}

void bottom_up() {
    for(int i = n/2; i>=1; i--) {
        sift_down(i);
    }
}

void heapsort() {
    int copy = n;
    while(n--) {
        swap(arr[1], arr[n]);
        sift_down(1);
    }
    n = copy;
}

int main() {

    n=1;

    while(1) {
        printf("1 to insert, 2 to query top, 3 to pop, 4 to print, 5 to heapsort, 6 to construct a heap bottom-up, otherwise exit\n");
        int opt;
        scanf("%d", &opt);
        if(opt == 1) {
            printf("Enter the number\n");
            int num;
            scanf("%d", &num);
            arr[n++] = num;
            bubble_up(n-1);
        }
        else if(opt == 2) {
            if(n==1)
                printf("empty\n");
            else 
                printf("%d\n", arr[1]);
        }
        else if(opt == 3) {
            if(n==1)
                printf("empty\n");
            else {
                n--;
                swap(arr[1], arr[n]);
                sift_down(1);
            }
        }
        else if(opt == 4) {
            if(n==1)
                printf("empty\n");
            else {
                for(int i=1; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
            }
        }
        else if(opt == 5) {
            printf("enter the number of elements\n");
            scanf("%d", &n);
            n++;
            printf("Enter the elements\n");
            for(int i=1; i < n; i++)
                scanf("%d", &arr[i]);
            bottom_up();
            heapsort();
        }
        else if(opt == 6) {
            printf("enter the number of elements\n");
            scanf("%d", &n);
            n++;
            printf("Enter the elements\n");
            for(int i=1; i < n; i++)
                scanf("%d", &arr[i]);
            bottom_up();
        }
        else {
            break;
        }
    }


    return 0;
}