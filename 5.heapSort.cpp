#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap{
    private:
        vector <int> h;
        int parent(int i){return (i-1)/2;}
        int left(int i){return 2*i+1;}
        int right(int i){return 2*i+2;}
        
        void shiftDown(int i){
            int minind=i;
            int r= right(i);
            int l= left(i);
            
            if (l<h.size() && h[l]<h[minind]){
                minind=l;  
                
            }
            if (r<h.size() && h[r]<h[minind]){
                minind=r;
            }
            
            

            
            if(minind!=i){
                swap(h[i],h[minind]);
                shiftDown(minind);
            }
            
        }
        
        void shiftUp(int i){
            if (i>0){
                if(h[i]<h[parent(i)]){
                    swap(h[i],h[parent(i)]);
                    shiftUp(parent(i));
                }
            }
            
        }
        
    public:
        Heap(vector<int> arr){
            h=arr;
            for(int i=(h.size()/2)-1;i>=0;i--){
                shiftDown(i);
            }
        }
        int extractMin(){
            
            swap(h[0],h[h.size()-1]);
            int rt=h.back();
            h.pop_back();
            shiftDown(0);
            
            return rt;
            
        }
        
        
        vector<int> HeapSort(){
            vector<int> rtarr;
            while(!(h.empty())){
                rtarr.push_back(extractMin());
            }
            return rtarr;
        }
    
};

int main() {
    vector<int> arr;
    arr.push_back(12);
    arr.push_back(11);
    arr.push_back(13);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    
    Heap h(arr);


    vector<int> sortedArr = h.HeapSort();


    cout << "Sorted array: ";
    for (int i=0;i<sortedArr.size();i++) {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    return 0;
}