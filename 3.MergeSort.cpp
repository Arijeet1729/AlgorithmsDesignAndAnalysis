#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


    int* Merge(int * arr, int left, int right,int mid){
        int na=mid-left+1;
        int nb=right-mid;

        int* a= (int*) malloc(na*sizeof(int));
        int* b= (int*) malloc(nb*sizeof(int));

        for (int i = 0; i < na; i++){
            a[i] = arr[left + i];
        }

        for (int i = 0; i < nb; i++){
            b[i] = arr[mid + 1 + i];
        }

        

        int aind=0;
        int bind=0;
        int cind=left;
        
        while (aind<na && bind<nb){
            if(a[aind]>b[bind]){
                arr[cind++]=b[bind++];
            }else{
                arr[cind++]=a[aind++];
            }
        }

        if(aind!=na){
            while (aind<na){
                arr[cind++]=a[aind++];
            }
        }
        else if (bind!=nb){
            while (bind<nb){
                arr[cind++]=b[bind++];
            }
        }
        
        return arr;
    };


    int* MergeSort(int* arr, int left, int right){

        if(left>=right){
            return arr;
        }
 
        int mid = left + (right - left) / 2;


        arr= MergeSort(arr,left,mid);
        arr= MergeSort(arr,mid+1,right);

        return Merge(arr,  left,  right , mid);
    }


int main(){
    int arr[10]={1,22,12,2,33,115,667,333,333,11};

    int* arr1=MergeSort(arr,0,10-1);

    for (int i = 0; i < 10; i++)
    {
        cout<<arr1[i]<<" ";
    }
    



    return 0;
}


