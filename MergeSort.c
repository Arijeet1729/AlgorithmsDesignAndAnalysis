#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* merge(int *B, int *C, int lenb, int lenc) {
    int* D = (int*)malloc((lenb + lenc) * sizeof(int));
    int b = 0, c = 0, d = 0;
    
    while (b < lenb && c < lenc) {
        if (B[b] <= C[c]) {
            D[d++] = B[b++];
        } else {
            D[d++] = C[c++];
        }
    }
    
    while (b < lenb) {
        D[d++] = B[b++];
    }
    
    while (c < lenc) {
        D[d++] = C[c++];
    }

    return D;
}

int* Mergesort(int *A, int n) {
    if (n < 2) {
        return A;
    }
    
    int mid = n / 2;

    int* B = (int*)malloc(mid * sizeof(int));
    int* C = (int*)malloc((n - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        B[i] = A[i];
    }
    for (int i = mid; i < n; i++) {
        C[i - mid] = A[i];
    }

    B = Mergesort(B, mid);
    C = Mergesort(C, n - mid);
    
    int* R = merge(B, C, mid, n - mid);

    free(B);
    free(C);

    return R;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int* sortedArr = Mergesort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");

    free(sortedArr);
    free(arr);
    return 0;
}