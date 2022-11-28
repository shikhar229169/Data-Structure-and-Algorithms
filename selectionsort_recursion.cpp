#include<iostream>
using namespace std;

void selectionSort(int arr[], int r, int c, int mx) {
    if (r==0) {
        return;
    }
    if (r>c) {
        if (arr[c]>arr[mx]) {
            selectionSort(arr, r, c+1, c);
        }
        else {
            selectionSort(arr, r, c+1, mx);
        }
    }
    else {
        int temp=arr[r-1];
        arr[r-1]=arr[mx];
        arr[mx]=temp;

        selectionSort(arr, r-1, 0, 0);
    }
}

int main() {
    int arr[]={7, 4, 1, 8, 54, 78, 69, 4};
    selectionSort(arr, 8, 0, 0);
    for (int i=0; i<8; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}