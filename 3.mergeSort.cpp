#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> Merge(vector <int> a, vector <int> b){
    int i=0;
    int j=0;
    vector <int> c;
    
    while(i<(int)a.size() && j<(int)b.size()){
        if(a[i]<b[j]){
            c.push_back(a[i++]);
        }else{
            c.push_back(b[j++]);
        }
    }
    
    if(i<(int)a.size()){
        while(i<(int)a.size()){
             c.push_back(a[i++]);
        }
    }else if(j<(int)b.size()){
        while(j<(int)b.size()){
            c.push_back(b[j++]);
        }
    }
    
    return c;
}


vector <int> mergeSort(vector<int> arr, int l, int r){
    if(l==r){
        vector <int> t; 
        t.push_back(arr[l]);
        return t;
    }
    int mid=(l+r)/2;
    
    vector<int> a = mergeSort(arr,l,mid);
    vector<int> b = mergeSort(arr,mid+1,r);
    
    
    return Merge(a,b);
}

int main() {
    vector<int> arr;
    arr.push_back(12);
    arr.push_back(11);
    arr.push_back(13);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);


    vector<int> sortedArr = mergeSort(arr, 0, arr.size() - 1);


    cout << "Sorted array: ";
    for (int i=0;i<(int)sortedArr.size();i++) {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    return 0;
}