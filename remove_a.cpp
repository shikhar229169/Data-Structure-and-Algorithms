#include<iostream>
using namespace std;

void remove_a(string s, int i) {
    if (i==s.length()) {
        cout<<endl;
        return;
    }
    if (s[i]!='a') {
        cout<<s[i];
    }
    remove_a(s, i+1);
}

string skip_a(string s) {
    if (s=="") {
        return "";
    }
    if (s[0]=='a') {
        return skip_a(s.substr(1));
    }
    else {
        return s[0] + skip_a(s.substr(1));
    }
}

int starts_with(string s, string check) {
    if (check=="") return 1;
    if (s=="") return 0;

    if (s[0]!=check[0]) {
        return 0;
    }
    else {
        return starts_with(s.substr(1), check.substr(1));
    }
}

string removeApple(string s) {
    if (s=="") {
        return "";
    }

    if (starts_with(s, "apple")) {
        return removeApple(s.substr(5));
    }
    else {
        return s[0] + removeApple(s.substr(1));
    }
}

int main(){
    string s="cabapplebassabaapplec";
    //cout<<skip_a(s);

    cout<<removeApple(s);
    return 0;
}