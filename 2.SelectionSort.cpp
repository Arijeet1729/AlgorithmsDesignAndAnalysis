#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

   for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int CurrMin = INT_MAX;
        int minind = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < CurrMin) {
                CurrMin = arr[j];
                minind = j;
            }
        }
        swap(arr, minind, i);
    }

 for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}  
