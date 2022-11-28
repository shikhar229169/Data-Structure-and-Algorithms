#include<iostream>
using namespace std;

void cycleSort(int arr[], int N) {
    for (int i=0; i<N; i++) {
        while (arr[i]!=(i+1) && arr[i]!=arr[arr[i]-1]) {
            int temp=arr[i];
            arr[i]=arr[arr[i]-1];
            arr[temp-1]=temp;
        }
        if (arr[i]==arr[arr[i]-1] && arr[i]!=(i+1)) {
            arr[i]=0;
        }
    }
}

int main(){
    int arr[] = {1,2,0};
    cycleSort(arr, 3);
    for (int i=0; i<3; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}