#include<iostream>
using namespace std;

int findPivot(int arr[], int st, int end) {
    int piv=st;
    int i=st+1, j=end;
    while (i<=j) {
        while (i<=j && arr[i]<=arr[st]) {
            i++;
        }
        while (j>=i && arr[st]<=arr[j]) {
            j--;
        }
        if (i<j) {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }

    if (j>st) {
        int temp=arr[st];
        arr[st]=arr[j];     
        arr[j]=temp;
        piv=j;
    }

    return piv;
}

void QuickSort(int arr[], int i, int j) {
    if (i>=j) {
        return;
    }

    int pivot=findPivot(arr, i, j);
    QuickSort(arr, i, pivot-1);
    QuickSort(arr, pivot+1, j);
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    QuickSort(arr, 0, 4);
    for (int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
    }   
    cout<<endl;
    return 0;
}