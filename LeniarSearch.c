#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int key;

    scanf("%d",&n);

    scanf("%d",&key);

    int arr[n];

    for (int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    int* low= &arr[0];
    int* high=&arr[n];

    int k=1;

    while(high!=low){
        if(*low==key){
            printf("Found index is:- %d",k-1);
            break;
        }
        else{
            low=&arr[0+k];
            k++;
        }
    }
}
