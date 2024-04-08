#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void hanoi(int n, char source, char aux, char dest) {
    if(n == 1) {
        printf("\nMove disk 1 from %c for %c",source,dest);
        return;
    }
    hanoi(n-1,source,dest,aux);
    printf("\nMove disk %d from %c for %c",n,source,dest);
    hanoi(n-1,aux,source,dest);
}

int main() {
    printf("\nEnter the number of disks:\n");
    int n; scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}