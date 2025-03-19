#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

/**
 * @brief Swap the values at indices i and j in the heap array.
 * 
 * @param heap The heap array.
 * @param i Index of the first value to swap.
 * @param j Index of the second value to swap.
 */
void swap(int *heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

/**
 * @brief Get the index of the parent node for a given node.
 * 
 * @param i Index of the current node.
 * @return Index of the parent node.
 */
int parent(int i) {
    return (i - 1) / 2;
}

/**
 * @brief Get the index of the left child of a given node.
 * 
 * @param i Index of the current node.
 * @return Index of the left child.
 */
int leftChild(int i) {
    return (2 * i) + 1;
}

/**
 * @brief Get the index of the right child of a given node.
 * 
 * @param i Index of the current node.
 * @return Index of the right child.
 */
int rightChild(int i) {
    return (2 * i) + 2;
}

/**
 * @brief Restore the heap property by moving a node up in the heap.
 * 
 * @param heap The heap array.
 * @param i Index of the node to shift up.
 */
void shiftUp(int* heap, int i) {
    while (i > 0 && heap[parent(i)] < heap[i]) {
        swap(heap, parent(i), i);
        i = parent(i);
    }
}

/**
 * @brief Restore the heap property by moving a node down in the heap.
 * 
 * @param heap The heap array.
 * @param i Index of the node to shift down.
 * @param size The size of the heap.
 */
void shiftDown(int* heap, int i, int size) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= size && heap[l] > heap[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= size && heap[r] > heap[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(heap, i, maxIndex);
        shiftDown(heap, maxIndex, size);
    }
}

/**
 * @brief Insert a new element into the heap.
 * 
 * @param heap The heap array.
 * @param p The new element to insert.
 * @param size The size of the heap.
 */
void insert(int* heap, int p, int* size) {
    if (*size == MAX_SIZE - 1) {
        exit(0);  // Prevent overflow
    }
    heap[++(*size)] = p;
    shiftUp(heap, *size);
}

/**
 * @brief Extract the maximum element from the heap.
 * 
 * @param heap The heap array.
 * @param size The size of the heap.
 * @return The maximum element.
 */
int extractMax(int* heap, int* size) {
    if (*size < 0) {
        exit(0);  // Prevent underflow
    }
    int result = heap[0];
    heap[0] = heap[(*size)--];
    shiftDown(heap, 0, *size);
    return result;
}

/**
 * @brief Remove a node from the heap.
 * 
 * @param heap The heap array.
 * @param i Index of the node to remove.
 * @param size The size of the heap.
 */
void removeNode(int* heap, int i, int* size) {
    if (i < 0 || i > *size) {
        return;  // Invalid index
    }
    heap[i] = INFINITY;  // Set to a large value
    shiftUp(heap, i);
    extractMax(heap, size);  // Remove the max element
}

/**
 * @brief Change the priority of a node in the heap.
 * 
 * @param heap The heap array.
 * @param i Index of the node to change.
 * @param newPriority The new priority of the node.
 * @param size The size of the heap.
 */
void changePriority(int* heap, int i, int newPriority, int* size) {
    if (i < 0 || i > *size) {
        return;  // Invalid index
    }
    int oldPriority = heap[i];
    heap[i] = newPriority;
    if (newPriority > oldPriority) { //if new priority higher 
        shiftUp(heap, i); //shiftup
    } else { //if new priority lower 
        shiftDown(heap, i, *size); //shiftdown
    }
}

int main() {
    int heap[MAX_SIZE];  // Array to represent the heap
    int size = -1;       // Start with an empty heap

    // Insert elements into the heap
    printf("Inserting elements:\n");
    insert(heap, 10, &size);
    insert(heap, 20, &size);
    insert(heap, 15, &size);
    insert(heap, 30, &size);
    insert(heap, 25, &size);

    // Print the maximum element
    printf("Max element: %d\n", extractMax(heap, &size)); // Should print 30

    // Change the priority of an element
    printf("Changing priority of index 1 to 35\n");
    changePriority(heap, 1, 35, &size); // Change the priority of the element at index 1

    // Print the maximum element after priority change
    printf("Max element after change: %d\n", extractMax(heap, &size)); // Should print 35

    // Remove a node
    printf("Removing element at index 2\n");
    removeNode(heap, 2, &size); // Remove the element at index 2

    // Print the maximum element after removal
    printf("Max element after removal: %d\n", extractMax(heap, &size)); // Should print the new max

    return 0;
}