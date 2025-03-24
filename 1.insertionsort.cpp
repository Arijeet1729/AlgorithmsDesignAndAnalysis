#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int size, int lower, int upper) {
    for (int i = 0; i < size; ++i) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
}


void insertionSort(int* arr, int s, int* comparisons, int* swaps) {
    for (int i = 1; i < s; i++) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++; 
            arr[j + 1] = arr[j];
            j = j - 1;
            (*swaps)++; 
        }
        (*comparisons)++; 
        arr[j + 1] = key; 
        if (j + 1 != i) {
            (*swaps)++; 
        }
    }
}

int main() {
    srand(time(0));
    int size = (rand() % (20 - 1 + 1)) + 1;
    int lower = 0, upper = 3320000;              
    int* a = (int*)malloc(size * sizeof(int));   

    srand(time(0));

    generateRandomArray(a, size, lower, upper);

    

    printf("The unsorted array is: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    int comparisons = 0; // comparisons
    int swaps = 0;       //  swaps

    insertionSort(a, size, &comparisons, &swaps);

    printf("The sorted array is: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");


    printf("The size: %d",size);
    printf("\nNumber of comparisons: %d\n", comparisons);
    printf("Number of swaps: %d\n", swaps);

    free(a); 
    return 0;
}
