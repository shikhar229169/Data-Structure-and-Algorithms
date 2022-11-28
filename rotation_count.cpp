#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> arr) {
    int s=0, e=arr.size()-1;

    while (s<=e) {
        int mid=s+(e-s)/2;
        if (mid<e && arr[mid]>arr[mid+1]) {
            return mid;
        }
        if (mid>s && arr[mid]<arr[mid-1]) {
            return mid-1;
        }

        if (arr[mid]>arr[s]) {
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }

    return -1;
}

int main(){
    vector<int> arr={5, 6, 7, 8, 1, 2, 3, 4};
    int pivot=findPivot(arr);
    cout<<(pivot+1)<<endl;
    return 0;
}