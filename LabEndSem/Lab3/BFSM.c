#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void strmat(char* text, int n, char* pat, int m) {
    bool flag; int temp;
    for(int i = 0; i < n-m; i++) {
        flag = true;
        temp = i;
        for(int j = 0; j < m; j++) {
            if(text[temp++] != pat[j]) {
                flag = false;
                break;
            }
            if(flag) {
                printf("\nFound at index %d",i);
                return;
            }
        }
    }
}

int main() {
    printf("\nEnter the Text:\n");
    char* text = (char*) calloc(100,sizeof(char));
    scanf("%s",text);
    printf("\nEnter the Pattern:\n");
    char* pat = (char*) calloc(100,sizeof(char));
    scanf("%s",pat);
    strmat(text,strlen(text),pat,strlen(pat));
    return 0;
}