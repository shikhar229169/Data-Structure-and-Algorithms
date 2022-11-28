#include<iostream>
using namespace std;

int mergeBoth(int arr[], int st, int mid, int end) {
    int N=mid-st+1;
    int M=end-mid;

    int arr1[N];
    int arr2[M];

    for (int i=0; i<N; i++) {
        arr1[i]=arr[i+st];
    }
    for (int i=0; i<M; i++) {
        arr2[i]=arr[i+mid+1];
    }

    int i=0, j=0, k=st;
    int inversions=0;

    while (i<N && j<M) {
        if (arr1[i]<=arr2[j]) {
            arr[k]=arr1[i];
            i++;
        }
        else {
            inversions += (N-i);
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }

    while (i<N) {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while (j<M) {
        arr[k]=arr2[j];
        j++;
        k++;
    }

    return inversions;
}

int mergeSort(int arr[], int i, int j) {
    if (i>=j) {
        return 0;
    }

    int mid = i + (j-i)/2;
    int inversions=0;

    inversions += mergeSort(arr, i, mid);
    inversions += mergeSort(arr, mid+1, j);

    inversions += mergeBoth(arr, i, mid, j);

    return inversions;
}

int main(){
    int arr[]={1, 2, 5, 3, 1, 7, 3, 1, 8};
    cout<<mergeSort(arr, 0, 8);
    return 0;
}