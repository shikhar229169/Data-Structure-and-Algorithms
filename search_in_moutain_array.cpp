#include<iostream>
#include<vector>
using namespace std;

int find_peek(vector<int>& arr) {
    int s=0, e=arr.size()-1;

    while (s<e) {
        int mid = s + (e-s)/2;

        if (arr[mid]<arr[mid+1]) {
            s=mid+1;
        }
        else {
            e=mid;
        }
    }

    return s;
}

int binary_search(vector<int>& arr, int target, int cmp, int s, int e) {
    while (s<=e) {
        int mid=s+(e-s)/2;

        if (arr[mid]==target) {
            return mid;
        }
        else if (arr[mid]>target) {
            if (cmp) {
                e=mid-1;
            }
            else {
                s=mid+1;
            }
        }
        else {
            if (cmp) {
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr={1, 2, 5, 7, 9, 4, 3, 2, 1};
    int target=3;
    int peak=find_peek(arr);
    int idx=binary_search(arr, target, 1, 0, peak);
    if (idx==-1) {
        idx=binary_search(arr, target, 0, peak+1, arr.size()-1);
    }
    cout<<idx<<endl;
    return 0;
}