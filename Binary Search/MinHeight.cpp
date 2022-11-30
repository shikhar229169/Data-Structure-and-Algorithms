#include<iostream>
using namespace std;

// link to the problem
// https://www.spoj.com/problems/EKO/

long long minimizeHeight(long long arr[], long long N, long long M) {
    long long st=0, end=0;
    for (int i=0; i<N; i++) {
        end=max(end, arr[i]);
    }

    long long minHeight;

    while (st<=end) {
        long long mid = st + (end-st)/2;

        long long woodExtracted=0;
        for (int i=0; i<N; i++) {
            woodExtracted+=max(arr[i]-mid, (long long)0);
        }

        if (woodExtracted>=M) {
            minHeight=mid;
            st=mid+1;
        }
        else {
            end=mid-1;
        }
    }

    return minHeight;
}

int main(){
    long long N, M;
    cin>>N>>M;

    long long arr[N];
    for (int i=0; i<N; i++) {
        cin>>arr[i];
    }
    cout<<minimizeHeight(arr, N, M)<<endl;
    return 0;
}