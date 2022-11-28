//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include<iostream>
#include<vector>
using namespace std;

int findDays(vector<int>& weights, int weight) {
    int days=1;
    int wt=0;

    for (int i: weights) {
        if ((wt + i)>weight) {
            days++;
            wt=i;
        }
        else {
            wt+=i;
        }
    }

    return days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int start=1, end=0;
    for (int i: weights) {
        start=max(start, i);
        end+=i;
    }

    while (start<end) {
        int mid = start + (end - start) / 2;

        int myDays=findDays(weights, mid);

        if (myDays>days) {
            start = mid + 1;
        }
        else {
            end=mid;
        }
    }

    return start;
}

int main(){
    vector<int> weights={1,2,3,1,1};
    int days=4;
    cout<<shipWithinDays(weights, days)<<endl;
    return 0;
}