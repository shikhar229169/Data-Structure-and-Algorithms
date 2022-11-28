#include<iostream>
#include<vector>
using namespace std;

void factors(int N) {
    vector<int> nums;
    for (int i=1; i*i<=N; i++) {
        if (N%i==0) {
            cout<<i<<" ";
            if ((N/i)!=i) {
                nums.push_back(N/i);
            }
        }
    }
    for (int i=nums.size()-1; i>=0; i--) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

int main(){
    int N=100;
    //factors(N);

    int a=48, b=484;
    cout<<gcd(a, b)<<endl;
    cout<<lcm(a, b)<<endl;
    return 0;
}