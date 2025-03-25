#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;


int Partition(vector<int> &arr, int l, int r){
    
    int pivot= arr[l];
    
    int i=l;
    int j=l+1;
    while(j<=r){
        if(arr[j]<pivot){
            swap(arr[++i],arr[j]);
        }
        j++;
    }
    swap(arr[i],arr[l]);
    
    return i;
    
}

void quickSort(vector <int> &arr,int l, int r){
    
    if (l<r){
        int pi=Partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
        
    }
    
    
    
}


int main() {
    vector<int> arr;
    arr.push_back(12);
    arr.push_back(11);
    arr.push_back(13);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);


    quickSort(arr, 0, arr.size() - 1);


    cout << "Sorted array: ";
    for (int i=0;i<arr.size();i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}