#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=3;

    int A[]={3,2,5};
    int B[]={5,1,2};

    int arr[n][n];

    int product[2*n-1];
    for(int i=0;i<2*n-1;i++){
        product[i]=0;
    }

    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            arr[i][j]=A[i]*B[j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            product[i+j]+=arr[i][j];
        }
    }
    
    for(int i=0;i<2*n-1;i++){
        printf("%d\t",product[i]);
    }

}
