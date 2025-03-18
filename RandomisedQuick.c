#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int Partition(int* A, int l, int r) {
    int pivot = A[l];
    int i = l;

    for (int j = l + 1; j <= r; j++) {
        if (A[j] < pivot) {
            i++;
            swap(A, i, j);
        }
    }
    swap(A, l, i);
    return i;
}

void Quick(int *A, int l, int r) {
    if (l < r) {
        srand(time(0));
        int k = rand()%(r-l+1);
        swap (A,l,k);
        int m = Partition(A, l, r);
        Quick(A, l, m - 1);
        Quick(A, m + 1, r);
    }
}

int main() {
    int arr[3] = {2, 1, 4};
    int n = 3; // Size of the array

    Quick(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
