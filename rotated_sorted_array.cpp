#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> arr) {
    int i=0, j=arr.size()-1;

    while (i<=j) {
        int mid = i + (j-i)/2;

        if (mid<j && arr[mid]>arr[mid+1]) {
            return mid;
        }
        if (mid>i && arr[mid]<arr[mid-1]) {
            return mid-1;
        }

        if (arr[mid]>arr[i]) {
            i=mid+1;
        }
        else if (arr[mid]<arr[i]) {
            j=mid-1;
        }
        else {
            if (arr[mid]>arr[j]) {
                i=mid+1;
            }
            else if (arr[mid]==arr[j]) {
                if (arr[i]>arr[i+1]) {
                    return i;
                }
                else {
                    i++;
                    j--;
                }
            }
            else {
                return j;
            }
        }
    }
    return -1;
}

int binary_search(vector<int>& arr, int target, int s, int e) {
    while (s<=e) {
        int mid=s+(e-s)/2;

        if (arr[mid]==target) {
            return mid;
        }
        else if (arr[mid]>target) {
            e=mid-1;
        }
        else {
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr={5, 5, 5, 5, 4, 5};
    int target=6;
    int pivot=findPivot(arr);
    int idx=-1;
    if (target>=arr[0]) {
        idx=binary_search(arr, target, 0, pivot);
    }
    else {
        idx=binary_search(arr, target, pivot+1, arr.size()-1);
    }
    cout<<pivot<<endl;
    return 0;
}