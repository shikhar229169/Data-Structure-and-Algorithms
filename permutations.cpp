#include<iostream>
#include<vector>
using namespace std;

void perm(string up, string p) {
    if (up=="") {
        cout<<p<<endl;
        return;
    }

    for (int i=p.length(); i>=0; i--) {
        perm(up.substr(1), p.substr(0, i) + up[0] + p.substr(i, p.length()-i));
    }
}

vector<string> perm_ret(string up, string p) {
    if (up=="") {
        vector<string> ans;
        ans.push_back(p);
        return ans;
    }
    vector<string> ans;
    for (int i=p.length(); i>=0; i--) {
        vector<string> curr=perm_ret(up.substr(1), p.substr(0, i) + up[0] + p.substr(i, p.length()-i));
        for (string k: curr) {
            ans.push_back(k);
        }
    }
    return ans;
}

int main(){
    string s="abc";
    vector<string> ans=perm_ret(s, "");

    for (auto i: ans) {
        cout<<i<<endl;
    }
    return 0;
}