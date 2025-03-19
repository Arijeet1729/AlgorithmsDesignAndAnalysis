#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > matrixConstructor(int n){
    vector< vector<int> > mat;
}

void mAdd(vector< vector<int> > A, vector< vector<int> > B, vector< vector<int> >&C, int splitz){

    for(int i=0;i<splitz;i++){
        for (int  j = 0; j < splitz; j++)
        {
            C[i][j]= A[i][j]+B[i][j];
        }
    }


}

void mDiff(vector< vector<int> > A, vector< vector<int> > B, vector< vector<int> >&C, int splitz){

    for(int i=0;i<splitz;i++){
        for (int  j = 0; j < splitz; j++)
        {
            C[i][j]= A[i][j]-B[i][j];
        }
    }


}



int main(){

    return 0;
}