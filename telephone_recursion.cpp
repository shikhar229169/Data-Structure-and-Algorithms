#include<iostream>
#include<map>
using namespace std;

map<int, string> mp;

void telephone(string up, string p) {
    if (up=="") {
        cout<<p<<endl;
        return;
    }

    string s=mp[up[0]];
    
    for (char c: s) {
        telephone(up.substr(1), p + c);
    }

}

int main(){
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";

    telephone("23", "");
return 0;
}