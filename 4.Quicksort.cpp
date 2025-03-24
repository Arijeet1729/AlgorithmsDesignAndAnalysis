#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int Partition(int *arr, int left , int right){
    int pivot= arr[left];
    int l =left;
    int r=left+1;
    while (r<=right){
        if(arr[r]<pivot){
            swap(arr[++l],arr[r++]);
        }else{
            r++;
        }
    }
    swap(arr[left], arr[l]);

    return l;
    
}



void QuickSort(int * arr, int left, int right){

    if (left >= right) return; 
    

    int part_ind=Partition(arr, left, right);
    
    QuickSort(arr, left,part_ind-1);
    QuickSort(arr,part_ind+1,right);

}

int main(){
    int arr[10]={1,22,12,2,33,115,667,333,333,11};

    QuickSort(arr,0,10-1);

    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}