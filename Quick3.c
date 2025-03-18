#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int* Partition(int* A, int l, int r) {
    int pivot = A[l];
    int i = l;
    int k = l;

    for (int j = l + 1; j <= r; j++) {
        if (A[j] < pivot) {
            i++;
            swap(A, i, j);
        } else if (A[j] == pivot) {
            k++;
            swap(A, k, j);
        }
    }
    int *arr = (int*)malloc(2 * sizeof(int));
    swap(A, l, i);
    arr[0] = i;
    arr[1] = k;
    return arr;
}

void Quick(int *A, int l, int r) {
    if (l < r) {
        int k = l + rand() % (r - l + 1);
        swap(A, l, k);
        int* m = Partition(A, l, r);
        Quick(A, l, m[0] - 1);
        Quick(A, m[1] + 1, r);
        free(m);
    }
}

int main() {
    srand(time(0));

    int arr[3] = {2, 1, -5};
    int n = 3;

    Quick(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
