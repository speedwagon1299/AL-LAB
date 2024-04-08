#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int max(int a, int b) {
    return (a>b)?a:b;
}

int main() {
    printf("\nEnter the number of items:\n");
    int n; scanf("%d",&n);
    int* wt = (int*) calloc(n,sizeof(int));
    int* pf = (int*) calloc(n,sizeof(int));
    printf("\nEnter the weights and profits respectively:\n");
    for(int i = 0; i < n; i++) {
        printf("\nWeight: ");   scanf("%d",&wt[i]);
        printf("Profit: ");    scanf("%d",&pf[i]);
    }
    printf("\nEnter the capacity of the knapsack:\n");
    int cap;    scanf("%d",&cap);
    int dp[n+1][cap+1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= cap; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else {
                if(j-wt[i-1] >= 0) {
                    if(j >= wt[i-1])
                        dp[i][j] = max(dp[i-1][j], max(dp[i-1][j], dp[i][j-wt[i-1]]) + pf[i-1]);
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j] + pf[i-1]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    printf("\nBest Shit: %d",dp[n][cap]);
    return 0;
}