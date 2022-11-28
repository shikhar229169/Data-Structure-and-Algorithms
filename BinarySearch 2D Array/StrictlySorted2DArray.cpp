#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>& arr, int target) {
    int start=0, end=arr.size()-1;

    while (start<=end) {
        int mid = start + (end - start) / 2;

        if (arr[mid]==target) {
            return mid;
        }
        else if (arr[mid]<target) {
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }

    return -1;
}

vector<int> search(vector<vector<int>>& arr, int target) {
    int N=arr.size(), M=arr[0].size();
    int start=0, end=arr.size()-1;
    vector<int> ans={-1, -1};

    while (start<=end) {
        int mid = start + (end - start) / 2;

        if (target>=arr[mid][0] && target<=arr[mid][M-1]) {
            // simple binary search on mid indexed vector
            int index=binary_search(arr[mid], target);
            if (index!=-1) {
                ans[0]=mid;
                ans[1]=index;
            }
            break;
        }
        else if (target>arr[mid][M-1]) {
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 12, 13}, {14, 15, 15, 16}};
    vector<int> ans=search(arr, 19);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}