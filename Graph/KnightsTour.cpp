#include<iostream>
#include<vector>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printKnightsTour(vector<vector<int>>& chess, int N, int r, int c, int upcomingMove) {
    if (r<0 || r>=N || c<0 || c>=N) {
        return;
    }

    if (chess[r][c]) {
        return;
    }

    if (upcomingMove==N*N) {
        chess[r][c]=upcomingMove;
        display(chess);
        chess[r][c]=0;
        return;
    }

    chess[r][c]=upcomingMove;

    printKnightsTour(chess, N, r-2, c+1, upcomingMove + 1);
    printKnightsTour(chess, N, r-1, c+2, upcomingMove + 1);
    printKnightsTour(chess, N, r+1, c+2, upcomingMove + 1);
    printKnightsTour(chess, N, r+2, c+1, upcomingMove + 1);
    printKnightsTour(chess, N, r+2, c-1, upcomingMove + 1);
    printKnightsTour(chess, N, r+1, c-2, upcomingMove + 1);
    printKnightsTour(chess, N, r-1, c-2, upcomingMove + 1);
    printKnightsTour(chess, N, r-2, c-1, upcomingMove + 1);
    

    chess[r][c]=0;
}

int main() {
    int N, r, c;
    cin>>N>>r>>c;

    vector<vector<int>> grid(N, vector<int> (N, 0));

    printKnightsTour(grid, N, r, c, 1);
}