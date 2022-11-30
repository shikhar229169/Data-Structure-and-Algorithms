#include<iostream>
using namespace std;

// link to the problem
// https://www.spoj.com/problems/EKO/

long long int minimizeHeight(long long int arr[], int N, long long int M) {
    long long int st=0, long long int end=0;
    for (int i=0; i<N; i++) {
        end=max(end, arr[i]);
    }

    long long int minHeight;

    while (st<=end) {
        long long int mid = st + (end-st)/2;

        long long int woodExtracted=0;
        for (int i=0; i<N; i++) {
            woodExtracted+=max((long long int)0, arr[i]-mid);
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
    int N;
    long long int M;
    cin>>N>>M;

    long long int arr[N];
    for (int i=0; i<N; i++) {
        cin>>arr[i];
    }
    cout<<minimizeHeight(arr, N, M)<<endl;
    return 0;
}