#include<iostream>
#include<vector>
using namespace std;

int partitions_ct(vector<int>& arr, int sum) {
    int curr_sum=0;
    int partitions=0;

    for (int i: arr) {
        if ((curr_sum+i)>=sum) {
            partitions++;
            curr_sum=0;
        }
        else {
            curr_sum+=i;
        }
    }

    return partitions;
}

int splitArr(vector<int>& arr, int m) {
    int s=1, e=0;

    for (int i: arr) {
        s=min(s, i);
        e+=i;
    }

    int meow=0;

    while (s<=e) {
        int mid = s + (e-s)/2;

        int partitions=partitions_ct(arr, mid);

        if (partitions>=m) {
            meow=mid;
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }

    return meow;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    int ans=splitArr(arr, 6);
    cout<<ans<<endl;
    return 0;
}