#include<iostream>
#include<vector>
using namespace std;

vector<int> search(vector<vector<int>>& arr, int target) {
    int r=0, c=arr[0].size()-1;
    vector<int> ans={-1, -1};

    while (r<arr.size() && c>=0) {
        if (arr[r][c]==target) {
            ans[0]=r;
            ans[1]=c;
            break;
        }
        else if (arr[r][c]>target) {
            c--;
        }
        else {
            r++;
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> arr={{10, 20, 30, 40}, {15, 25, 35, 45}, {28, 29, 37, 49}, {33, 34, 38, 50}};
    vector<int> index=search(arr, 69);
    cout<<index[0]<<" "<<index[1]<<endl;
    return 0;
}