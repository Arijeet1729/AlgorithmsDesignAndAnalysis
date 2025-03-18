#include <stdio.h>
#include <stdlib.h>

int* Karatsuba(int* A, int* B,int n, int a, int b){

    int * R=(int *)malloc((2*n-1)*sizeof(int));
    
    for(int i=0;i<(2*n)-1;i++){
        R[i]=0;    
    }

    if (n==1){
        R[0]=A[a]*B[b];
        return R;
    }
    int mid=n/2;
    int* A0B0=Karatsuba(A,B,mid,a,b);
    int* A1B1=Karatsuba(A,B,n-mid,a+mid,b+mid);

    for (int i = 0; i < (2 * mid) - 1; i++){
        R[i]+=A0B0[i];
        R[i+n]+=A1B1[i];
    }

    int * R1=(int *)malloc((mid)*sizeof(int));
    int * R2=(int *)malloc((mid)*sizeof(int));

    for (int i=0;i<mid;i++){
        R1[i]+=A[a+i]+A[a+i+mid];
        R2[i]+=B[b+i]+B[b+i+mid];
    }

    int * A1pA0_B1pB0= Karatsuba(R1,R2,mid,0,0);

    for (int i = 0; i < (2 * mid) - 1; i++) {
        R[i+mid]+= A1pA0_B1pB0[i]-A1B1[i]-A0B0[i];
    }
    free(A0B0);
    free(A1B1);
    free(R1);
    free(R2);
    free(A1pA0_B1pB0);
    
    return R;

}



int main() {
    int n = 4;
    int A[] = {1, 2, 3, 4};
    int B[] = {1, 0, 2, 1};

    int* R = Karatsuba(A, B, n, 0, 0);

    for (int i = 0; i < 2 * n - 1; i++) {
        printf("%d ", R[i]);
    }
    printf("\n");

    free(R);

    return 0;
}
