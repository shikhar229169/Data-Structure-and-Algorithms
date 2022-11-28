#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsets(string un, string p) {
    if (un=="") {
        if (p!="") cout<<p<<endl;
        else cout<<"NULL"<<endl;
        return;
    }
    subsets(un.substr(1), p+un[0]);
    subsets(un.substr(1), p);
}

vector<string> subsets_diff(string un, string p) {
    static vector<string> ans;
    if (un=="") {
        ans.push_back(p);
        return ans;
    }
    
    ans=subsets_diff(un.substr(1), p+un[0]);
    ans=subsets_diff(un.substr(1), p);
    return ans;
}

vector<vector<int>> subsets_iterative(vector<int> arr) {
    vector<vector<int>> ans;
    ans.push_back({});

    for (int i: arr) {
        int N=ans.size();
        for (int j=0; j<N; j++) {
            vector<int> temp=ans[j];
            temp.push_back(i);
            ans.push_back(temp);
        }
    }

    return ans;
}

vector<vector<int>> dup_subset(vector<int> arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    ans.push_back({});
    int prev=1;
    
    for (int i=0; i<arr.size(); i++) {
        int start=0;
        int N=ans.size();
        if (i>0 && arr[i]==arr[i-1]) {
            start=N-prev;
        }
        
        for (int j=start; j<N; j++) {
            vector<int> aux=ans[j];
            aux.push_back(arr[i]);
            ans.push_back(aux);
        }

        prev=N-start;
    }
    return ans;
}

int main(){
    /*
    string s="abc";
    subsets(s, "");

    vector<string> ans=subsets_diff(s, "");
    for (auto i: ans) {
        cout<<i<<endl;
    }
    */
    vector<int> arr={1, 2, 2, 2};
    vector<vector<int>> ans=dup_subset(arr);
    for (auto i: ans) {
        if (i.size()==0) {
            cout<<"NULL";
        }
        for (auto j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}