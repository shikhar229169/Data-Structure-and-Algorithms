#include<iostream>
#include<algorithm>
using namespace std;

long long int findCoins(int arr[], int N, int k, int D) {
    int size=k+1;
    int r=D/size;
    int extra=D%size;

    long long int coins=0;
    long long int sum=0;

    for (int i=0; i<min(N, size); i++) {
        sum+=arr[i];
    }

    coins+=(r*sum);

    for (int i=0; i<min(N, extra); i++) {
        coins+=arr[i];
    }

    return coins;
}

int main(){
    int T;
    cin>>T;
    while (T--) {
        int N, D;
        long long int C;
        cin>>N>>C>>D;

        int arr[N];
        for (int i=0; i<N; i++) {
            cin>>arr[i];
        }
        sort(arr, arr + N, greater<int>());

        int st=0, end=D;
        int k=-1;

        while (st<=end) {
            int mid = st + (end-st)/2;

            long long int coins=findCoins(arr, N, mid, D);

            if (coins<C) {
                end=mid-1;
            }
            else {
                k=mid;
                st=mid+1;
            }
        }
        
        if (st==D+1) {
            cout<<"Infinity"<<endl;
        }
        else if (end==-1) {
            cout<<"Impossible"<<endl;
        }
        else {
            cout<<k<<endl;
        }
    } 
    return 0;
}