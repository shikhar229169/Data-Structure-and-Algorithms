#include<iostream>
using namespace std;

void dice(int num, string p) {
    if (num==0) {
        cout<<p<<endl;
        return;
    }

    for (int i=1; i<=6; i++) {
        if (i>num) break;
        dice(num-i, p + (char)(i+'0'));
    }
}

int main(){
    int n=4;
    dice(n, "");
    return 0;
}