#include<iostream>
#include<vector>
using namespace std;

void print_vector(vector<vector<int>>& board) {
    for (auto i: board) {
        for (auto j: i) {
            cout<<abs(j)<<" ";
        }
        cout<<endl;
    }
}

int do_it(int i) {
    if (i>=0 && i<=2) return 0;
    if (i>=3 && i<=5) return 3;
    return 6;
}

int is_valid(vector<vector<int>>& board, int r, int c, int val) {
    for (int i=0; i<9; i++) {
        if (abs(board[i][c])==val) {
            return 0;
        }
    }

    for (int i=0; i<9; i++) {
        if (abs(board[r][i])==val) {
            return 0;
        }
    }

    int x=do_it(r);
    int y=do_it(c);
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (abs(board[x+i][y+j])==val) {
                return 0;
            }
        }
    }
    return 1;
}

int SudokuSolve(vector<vector<int>>& board, int r, int c) {
    if (r==board.size()) {
        // answer found
        return 1;
    }
    if (c==board.size()) {
        return SudokuSolve(board, r+1, 0);
    }

    if (board[r][c]>=1 && board[r][c]<=9) {
        return SudokuSolve(board, r, c+1);
    }

    for (int i=-1; i>=-9; i--) {
        int res=0;
        if (is_valid(board, r, c, abs(i))) {
            board[r][c]=i;
            res=SudokuSolve(board, r, c+1);
            if (res==1) return res;
            board[r][c]=0;
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> board(9, vector<int>(9, 0));
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            int x;
            cin>>x;
            board[i][j]=x;
        }
    }
    SudokuSolve(board, 0, 0);
    print_vector(board);
    return 0;
}