#include <stdio.h>
#include <stdlib.h>

int* PolyMulti1(int* A, int* B, int n, int a, int b) {
    int* R = (int*)malloc((2*n - 1) * sizeof(int));
    
    if (n == 1) {
        R[0] = A[a] * B[b];
        return R;
    }

    int* A0B0 = PolyMulti1(A, B, n/2, a, b);
    int* A1B1 = PolyMulti1(A, B, n/2, a + n/2, b + n/2);
    int* A0B1 = PolyMulti1(A, B, n/2, a, b + n/2);
    int* A1B0 = PolyMulti1(A, B, n/2, a + n/2, b);

    for (int i = 0; i < 2*n - 1; i++) {
        R[i] = 0; 
    }

    for (int i = 0; i < n - 1; i++) {
        R[i] += A0B0[i];
        R[i + n] += A1B1[i];
    }

    for (int i = 0; i < n; i++) {
        R[i + n/2] += A0B1[i];
        R[i + n/2] += A1B0[i];
    }

    free(A0B0);
    free(A1B1);
    free(A0B1);
    free(A1B0);

    return R;
}

int main() {
    int n = 4; 
    int A[] = {1, 2, 3, 4}; 
    int B[] = {1, 0, 2, 1}; 

    int* R = PolyMulti1(A, B, n, 0, 0);

    for (int i = 0; i < 2*n - 1; i++) {
        printf("%d ", R[i]);
    }
    printf("\n");

    free(R);

    return 0;
}