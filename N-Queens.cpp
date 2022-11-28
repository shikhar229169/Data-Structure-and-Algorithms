#include<iostream>
#include<vector>
using namespace std;

void print_vector(vector<string>& maze) {
    for (auto i: maze) {
        for (auto j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


int is_valid(vector<string>& Board, int r, int c) {
    for (int i=0; i<r; i++) {
        if (Board[i][c]=='Q') {
            return 0;
        }
    }
    int i=r-1, j=c+1;
    int lm=min(r, (int)Board.size()-c-1);
    for (int k=1; k<=lm; k++) {
        if (Board[i][j]=='Q') {
            return 0;
        }
        i--;
        j++;
    }

    i=r-1, j=c-1;
    lm=min(r, c);
    for (int k=1; k<=lm; k++) {
        if (Board[i][j]=='Q') {
            return 0;
        }
        i--;
        j--;
    }
    return 1;
}

void N_Queen(vector<string>& Board, int r) {
    if (r==Board.size()) {
        cout<<endl;
        print_vector(Board);
        return;
    }

    for (int i=0; i<Board.size(); i++) {
        if (is_valid(Board, r, i)) {
            Board[r][i]='Q';
            N_Queen(Board, r+1);
            Board[r][i]='.';  
              // backtracking: reverting all the changes as the above recursive calls are returned back from where it was called
        }
    }
}


int main(){
    int N=10;
    vector<string> Board(N);
    string temp="";
    for (int i=1; i<=N; i++) {
        temp+='.';
    }
    for (int i=0; i<N; i++) {
        Board[i]=temp;
    }
    N_Queen(Board, 0);
    cout<<"meow"<<endl;
    return 0;
}