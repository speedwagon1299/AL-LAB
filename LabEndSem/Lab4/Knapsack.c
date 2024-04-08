#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void partition(int* prof, int* wt, int n, int cap) {
    int temp, sum_prof, sum_wt, max_sum_prof = 0;
    for(int i = 1; i < pow(2,n); i++) {
        temp = i;
        sum_prof = sum_wt = 0;
        for(int j = 0; j < n; j++) {
            if(temp%2 == 1) {
                sum_wt += wt[j];
                sum_prof += prof[j];
            }
            temp>>= 1;
        }
        if(sum_wt <= cap) {
            if(sum_prof > max_sum_prof) {
                max_sum_prof = sum_prof;
            }
        } 
    }
    printf("\nMax Profit: %d",max_sum_prof);
}

int main() {
    printf("\nEnter the number of elements:\n");
    int n; scanf("%d",&n);
    int* prof = (int*) calloc(n,sizeof(int));
    int* wt = (int*) calloc(n,sizeof(int));
    printf("\nEnter the profit and weight respectively:\n");
    for(int i = 0; i < n; i++) {
        printf("\nProfit:\t"); scanf("%d",&prof[i]);
        printf("Weight:\t"); scanf("%d",&wt[i]);
    }
    printf("\nEnter the capacity:\n");
    int cap; scanf("%d",&cap);
    partition(prof,wt,n,cap);
    return 0;
}