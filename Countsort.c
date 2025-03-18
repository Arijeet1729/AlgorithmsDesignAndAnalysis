#include <stdio.h>
#include <stdlib.h>

int *csort(int* A, int M, int n){
    int *count = (int *) calloc(M+1, sizeof(int));

    for (int i=0;i<n;i++){
        count[A[i]]+=1;
    }
    

    int * Pos =(int *) calloc(M+1,sizeof(int));
    int * Ad =(int *) calloc(n,sizeof(int));

    Pos[0]=0;
    for(int i=1;i<=M;i++){
        Pos[i]=Pos[i-1]+count[i-1];
    }

 for(int i=0;i<n;i++){
        Ad[Pos[A[i]]]=A[i];
        Pos[A[i]]++;
    }
    return Ad;
      
}

int main(){
    int arr[5]={3,2,4,5,5};
    int* sortedArr=csort(arr,5,5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");

    return 0;
}

