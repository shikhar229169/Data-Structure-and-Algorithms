#include<iostream>
#include<vector>
using namespace std;

int partitions_ct(vector<int>& arr, int sum) {
    int curr_sum=0;
    int partitions=1;

    for (int i: arr) {
        if ((curr_sum+i)>sum) {
            partitions++;
            curr_sum=i;
        }
        else {
            curr_sum+=i;
        }
    }

    return partitions;
}

int splitArr(vector<int>& arr, int m) {
    int s=0, e=0;

    for (int i: arr) {
        s=max(s, i);
        e+=i;
    }

    while (s<e) {
        int mid = s + (e-s)/2;

        int partitions=partitions_ct(arr, mid);

        if (partitions>m) {
            s=mid+1;
        }
        else {
            e=mid;
        }
    }

    return s;
}

int main(){
    vector<int> arr={12, 34, 67, 90};
    int ans=splitArr(arr, 2);
    cout<<ans<<endl;
    return 0;
}