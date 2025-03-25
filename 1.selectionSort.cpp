#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector <int> &arr){
    for(int i=0;i<arr.size();i++){
        int mini=i;
        for(int j=i;j<arr.size();j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        if(mini !=i){
            swap(arr[i],arr[mini]);
        }
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};  
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    selectionSort(arr);  // Sorting

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}