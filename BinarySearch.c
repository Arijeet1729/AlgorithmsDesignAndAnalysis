
#include <stdio.h>
#include <stdlib.h>

int BS(int* arr, int low,int high, int key){
    if (high<low){
        return low-1;
    }

    int mid =low+(high-low)/2;

    if (arr[mid]==key){
        return mid;
    }
    else if(key<arr[mid]){
        return BS(arr,mid-1,high,key);
    }
    else if(key >arr[mid]){
        return BS(arr,low,mid+1,key);
    }
    return 0;
}

int main(){
    int n;
    int key;

    scanf("%d",&n);
    scanf("%d",&key);

    int arr[n];

    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int low= 0;
    int high= n-1;

    printf("%d",BS(arr,low,high,key));
}
