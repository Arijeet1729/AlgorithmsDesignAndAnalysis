#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    int val;
    int wt;
    double valperwt;
}ele;

bool operator<(const ele &a, const ele &b){
    return(a.valperwt>b.valperwt);
}

double fractionalKnapsack(vector<ele> v, int W){
    sort(v.begin(),v.end());
    
        double profit = 0.0;
        int i=0;
        int n=v.size();
    
    while(W>0 && i < n ){
        if (v[i].wt<=W){
            profit+=v[i].val;
            W-=v[i].wt;
        }else{
            profit+=v[i].valperwt*W;
            W=0;
        }
        i++;
    }
    
    
    
    
    return profit;
}

int main(){
    cout <<"Enter the number of items"<<endl;
    int n;
    cin>>n;
    
    vector<ele> arr;
    
    for(int i=0;i<n;i++){
        int a ,b;
        cin>>a>>b;
        double d=static_cast<double>(a) / b;;
        arr.push_back({a, b, d});
    }
    
    cout<< fractionalKnapsack(arr,30);
    
}


