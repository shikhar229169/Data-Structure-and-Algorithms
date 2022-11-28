#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while (T--) {
        int N, X;
        cin>>N>>X;
        
        if (N%X!=0) {
            cout<<-1<<endl;
            continue;
        }

        int arr[N+1];
        cout<<X<<" ";
        int k=2;
        int c=0;
        for (int i=2; i<N; i++) {
            if (X==i && !c) {
                arr[i]=N;
                c=i;
            }
            else {
                arr[i]=k;
            }
            k++;
        }
        
        for (int i=c+1; i<N && c; i++) {
            
            if (arr[i]%c==0 && arr[c]%arr[i]==0) {
                int temp=arr[i];
                arr[i]=arr[c];
                arr[c]=temp;
                c=i;
            }
        }

        for (int i=2; i<N; i++) {
            cout<<arr[i]<<" ";
        }

        cout<<1<<endl;
    }
    return 0;
}