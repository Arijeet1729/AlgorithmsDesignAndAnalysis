#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int e1,int e2){
    int temp=a[e1];
    a[e1]=a[e2];
    a[e2]=temp;
}

void selectionSort(int* arr,int s){
    for(int i=0;i<s;i++){
        int minind=i;
        for(int j=i;j<s;j++){
            if(arr[j]<arr[minind]){
                minind=j;
            }
        }
        if(minind!=i){
            swap(arr,i,minind);
        }
    }
}


int main(){
    int a[]={34,22,11,54,5,100,1123,11};
    int size= sizeof(a)/sizeof(int);
    selectionSort(a,size);
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }

}