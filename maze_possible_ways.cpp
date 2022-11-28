#include<iostream>
#include<vector>
using namespace std;

int ways_to_reach(int r, int c, string p) {
    if (r==1 && c==1) {
        return 0;
    }
    if (r==1) {
        for (int i=1; i<c; i++) {
            p = p + 'R';
        }
        cout<<p<<endl;
        return 1;
    }
    if (c==1) {
        for (int i=1; i<r; i++) {
            p = p + 'D';
        }
        cout<<p<<endl;
        return 1;
    }

    int way1=ways_to_reach(r-1, c, p + 'D');
    int way2=ways_to_reach(r, c-1, p + 'R');

    return way1 + way2;
}

void ways_to_reach_diag(int r, int c, string p) {
    if (r==1 && c==1) {
        cout<<p<<endl;
        return;
    }

    if (r>1) {
        ways_to_reach_diag(r-1, c, p + 'D');
    }
    if (r>1 && c>1) {
        ways_to_reach_diag(r-1, c-1, p + 'S');
    }
    if (c>1) {
        ways_to_reach_diag(r, c-1, p + 'R');
    }
}

void path_with_obs(vector<vector<int>>& path, int r, int c, string p) {
    if (path[r][c]==1) {                    // 1 signifies obstacle in the path
        return;
    }  
    if (r==path.size()-1 && c==path[r].size()-1) {
        cout<<p<<endl;
        return;
    }

    if (r<path.size()-1) {
        path_with_obs(path, r+1, c, p + 'D');
    }
    if (c<path[r].size()-1) {
        path_with_obs(path, r, c+1, p + 'R');
    }
}

void print_vector(vector<vector<int>>& ans) {
    cout<<endl;
    for (auto i: ans) {
        for (auto j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
// all possible ways with obstacles stored in maze array and to print the path in the form of array as well as string
void all_possible_ways(vector<vector<int>>& maze, int r, int c, vector<vector<int>>& ans, int lvl, string p) {
    if (!maze[r][c]) {
        return;
    }
    if (ans[r][c]) {
        return;
    }
    if (r==maze.size()-1 && c==maze[0].size()-1) {
        ans[r][c]=lvl;
        print_vector(ans);
        cout<<p<<endl;
        ans[r][c]=0;
        return;
    }
    
    ans[r][c]=lvl;

    if (r>0) {
        all_possible_ways(maze, r-1, c, ans, lvl+1, p + 'U');
    }
    if (c>0) {
        all_possible_ways(maze, r, c-1, ans, lvl+1, p + 'L');
    }
    if (r<maze.size()-1) {
        all_possible_ways(maze, r+1, c, ans, lvl+1, p + 'D');
    }
    if (c<maze[0].size()-1) {
        all_possible_ways(maze, r, c+1, ans, lvl+1, p + 'R');
    }

    ans[r][c]=0;
}


int main(){
    vector<vector<int>> path;
    vector<vector<int>> temp;
    int N=3, M=3;
    for (int i=0; i<N; i++) {
        vector<int> aux;
        vector<int> help;
        for (int j=0; j<M; j++) {
            int x;
            cin>>x;
            aux.push_back(x);
            help.push_back(0);
        }
        temp.push_back(help);
        path.push_back(aux);
    }
    
    all_possible_ways(path, 0, 0, temp, 1, "");
    return 0;
}