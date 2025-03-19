#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;


class heap{
    private:
        int* Heap;
        int sizeNotSorted;


        void swap(int i, int j) {
            int temp = Heap[i];
            Heap[i] = Heap[j];
            Heap[j] = temp;
        }


        int parent(int i){
            return (i-1)/2;
        }
        int left(int i){
            return 2*i+1;
        }
        int right(int i){
            return 2*i+2;
        }


        void shiftUp(int i){
            int l=parent(i);
            if ((i>0)&&(Heap[l]>Heap[i])){
                swap(parent(i),i);
                shiftUp(l);
            }
        }


        void shiftDown(int i){
            int MAX=i;

            if(left(i)<sizeNotSorted && Heap[left(i)]>Heap[MAX]){
                MAX=left(i);
            }

            if(right(i)< sizeNotSorted && Heap[right(i)]>Heap[MAX]){
                MAX=right(i);
            }
            
            if(MAX!=i){
                swap(i,MAX);
                shiftDown(MAX);
            }

        }


        int formattedExtractMax() {
            if (sizeNotSorted <= 0) {
                return -1;
            }

            int min = Heap[0];

                
            swap(0, sizeNotSorted - 1);
    
            sizeNotSorted--;

            shiftDown(0);
            return min;  
        }
    

        void buildHeap(){
            for(int i=sizeNotSorted/2-1;i>=0;i--){
                shiftDown(i);
            }
        }
    //end of private space

    public:
        heap(int* arr, int size){
            this->Heap=new int[size];
            this->sizeNotSorted=size;

            for (int i = 0; i < size; i++) {
                this->Heap[i] = arr[i];
            }
        }
        void heapSort(int * arr,int size){
            buildHeap();
            for (int i = sizeNotSorted - 1; i >= 1; i--) {
                swap(0, i);  // Move the current root to the end
                sizeNotSorted--;  // Reduce the heap size
                shiftDown(0);  // Restore the heap property from the root
            }
            for(int i=0;i<size;i++){
                arr[i]=Heap[i];
            }

        }

        
};


int main() {
    // Sample array
    int arr[] = {10, 20, 15, 30, 40, 50, 5};
    int size = sizeof(arr) / sizeof(arr[0]); 

    heap h(arr, size);

    // Perform heap sort
    printf("Performing heap sort...\n");
    h.heapSort(arr,size);

    // Print sorted elements
    printf("Sorted elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
