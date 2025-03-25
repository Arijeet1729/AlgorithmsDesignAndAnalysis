#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector <int> &arr){
    
    for(int i=1;i<arr.size();i++){
        int ele=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>ele){
            arr[j+1]=arr[j];
            j--;
        }
        arr[++j]=ele;
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};  
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    insertionSort(arr); 

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}