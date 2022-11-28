#include<iostream>
#include<vector>
using namespace std;

void print_vector(vector<vector<int>>& maze) {
    for (auto i: maze) {
        for (auto j: i) {
            if (j==-1) cout<<0<<" ";
            else cout<<j<<" ";
        }
        cout<<endl;
    }
}

void all_possible_paths(vector<vector<int>>& maze, int r, int c, int path) {
    if (r==maze.size()-1 && c==maze[0].size()-1) {
        cout<<endl;
        maze[r][c]=path;
        print_vector(maze);
        maze[r][c]=0;
        cout<<endl;
        return;
    }

    if (maze[r][c]) {
        return;
    }

    maze[r][c]=path;

    if (r>0) {
        all_possible_paths(maze, r-1, c, path+1);
    }
    if (c>0) {
        all_possible_paths(maze, r, c-1, path+1);
    }
    if (r<maze.size()-1) {
        all_possible_paths(maze, r+1, c, path+1);
    }
    if (c<maze[0].size()-1) {
        all_possible_paths(maze, r, c+1, path+1);
    }

    maze[r][c]=0;
}

int main(){
    vector<vector<int>> maze;
    int N=3, M=3;
    for (int i=0; i<N; i++) {
        vector<int> aux;
        for (int j=0; j<M; j++) {
            int x;
            cin>>x;
            aux.push_back(x);
        }
        maze.push_back(aux);
    }

    all_possible_paths(maze, 0, 0, 1);
    return 0;
}