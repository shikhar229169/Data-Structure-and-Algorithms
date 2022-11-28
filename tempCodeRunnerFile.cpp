#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int T;
    cin>>T;

    while (T--) {
        long long l, r, x, a, b;
        cin>>l>>r>>x>>a>>b;

        if (a==b) {
            cout<<0<<endl;
            continue;
        }
        if (abs(a-b)>=x) {
            cout<<1<<endl;
            continue;
        }


        int steps1=0;
        int steps2=0;

        if (abs(a-l)>=x) {
            if (abs(l-b)>=x) {
                steps1+=2;
            }
            else if (abs(l-r)>=x && abs(r-b)>=x) {
                steps1+=3;
            }
        }
        if (abs(a-r)>=x) {
            if (abs(r-b)>=x) {
                steps2+=2;
            }
            else if (abs(r-l)>=x && abs(l-b)>=x) {
                steps2+=3;
            }
        }
        if (steps1 && steps2) {
            cout<<min(steps1, steps2)<<endl;
        }
        else if (steps1) {
            cout<<steps1<<endl;
        }
        else if (steps2) {
            cout<<steps2<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
    return 0;
}