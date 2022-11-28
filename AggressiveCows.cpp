#include<iostream>
#include<algorithm>
using namespace std;

int place_cows(int arr[], int N, int dist) {
    int cows=1;
    int prev=arr[0];

    for (int i=1; i<N; i++) {
        if ((arr[i]-prev)>=dist) {
            cows++;
            prev=arr[i];
        }
    }

    return cows;
}

int max_dist(int arr[], int N, int C) {
    int s=1, e=arr[N-1]-arr[0];

    for (int i=1; i<N; i++) {
        s=min(s, arr[i]-arr[i-1]);
    }

    int max_dist=0;

    while (s<=e) {
        int mid = s + (e - s) / 2;            // guess distance between cows

        int cows=place_cows(arr, N, mid);     // calculating no of cows can be placed with distance equal to mid

        if (C>cows) {
            e=mid-1;
        }
        else {
            max_dist=mid;                     // can be the potential answer
            s=mid+1;                          // but the actual answer may lie ahead
        }
    }

    return max_dist;
}

int main(){
    int T;
    cin>>T;
    while (T--) {
    	int N, C;
    	cin>>N>>C;
    	int arr[N];
    	for (int i=0; i<N; i++) {
    		cin>>arr[i];
    	}
    	sort(arr, arr + N);
    	cout<<max_dist(arr, N, C)<<endl;
    }
    return 0;
}