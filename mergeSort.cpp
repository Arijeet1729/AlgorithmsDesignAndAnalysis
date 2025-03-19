#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void merge(int*arr, int l,int m, int r){
    
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }

    
    
    int* ptr1=L;
    int* ptr2=R;

    int* eptr1=L+n1;
    int* eptr2=R+n2;

    int i=0;
    int k=l;
    
    while(ptr1!=eptr1 && ptr2!=eptr2){
        if(*ptr1 <= *ptr2){
            arr[k++]= *ptr1;
            ptr1++;

        }else if(*ptr2 < *ptr1){
            arr[k++]= *ptr2;
            ptr2++;
        }
    }
    
    if(ptr1!=eptr1){
        while(ptr1!=eptr1){
            arr[k++]= *ptr1;
            ptr1++;
        }
    }else if(ptr2!=eptr2){
        while (ptr2!=eptr2)
        {
            arr[k++]= *ptr2;
            ptr2++;
        }
    }
}

void mergeSort(int* arr,int l,int r){
    if(l>=r){
        return;
    }
        int mid = l +((r - l) / 2);

        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r );
}

int main(){

    int arr[10]={23,34,12,34,12,123232,23232,223,2323,22};

    mergeSort(arr,0,10);
    for(int i=0;i<10;i++){
        std::cout<<arr[i]<<" ";
    }

    return 0;
}
