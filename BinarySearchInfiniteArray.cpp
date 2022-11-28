#include<iostream>
using namespace std;

int infinite_search(int arr[], int target) {
    int i=0, j=0;

    while (true) {
        if (arr[i]>target) {
            return -1;
        }
        if (target<=arr[j]) {
            break;
        }
        int size=(j-i+1)*2;
        i=j+1;
        j=i+size-1;
    }

    while (i<=j) {
        int mid=i+(j-i)/2;
        if (arr[mid]==target) {
            return mid;
        }
        else if (arr[mid]>target) {
            j=mid-1;
        }
        else {
            i=mid+1;
        }
    }

    return -1;
}

int main(){

    int arr[]={1, 3, 6, 7, 8, 12, 13, 15, 19, 22, 25, 26, 27, 28, 31};
    cout<<infinite_search(arr, 25 )<<endl;
    return 0;
}