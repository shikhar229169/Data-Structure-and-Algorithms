#include<iostream>
using namespace std;

double square_root(int N, int p) {
    int i=0, j=N;

    while (i<=j) {
        int mid=(i+j)/2;
        if (mid*mid==N) {
            return mid;
        }
        else if (mid*mid>N) {
            j=mid-1;
        }
        else {
            i=mid+1;
        }
    }

    double ans=j;
    
    double curr=1;
    for (int k=1; k<=p; k++) {
        curr=curr/10;
        while ((ans+curr)*(ans+curr)<(double)N) {
            ans+=curr;
        }
    }
    return ans;
}

double SquareRoot(int N) {
    double root=N;
    while (true) {
        double curr=(root+((double)N/root))*0.5;
        if (abs(curr-root)<0.01) {
            return curr;
        }
        root=curr;
    }
    return root;
}

int main(){
    cout<<square_root(69, 5)<<endl;
    cout<<SquareRoot(69);
return 0;
}