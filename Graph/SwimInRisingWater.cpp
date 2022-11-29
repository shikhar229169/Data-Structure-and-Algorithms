#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Using Dijkstra Algorithm

class Node {
public:
    int r;
    int c;
    int t;

    Node(int t, int r, int c)
    {
        this->r = r;
        this->c = c;
        this->t = t;
    }
};

class cmp {
public:
    bool operator()(Node p1, Node p2) {
        return p1.t > p2.t;
    }
};

int swimInWater(vector<vector<int>> &grid)
{
    int N = grid.size();
    int M = grid[0].size();
    priority_queue<Node, vector<Node>, cmp> q;
    Node node = Node(grid[0][0], 0, 0);
    q.push(node);
    vector<vector<int>> visited(N, vector<int>(M, 0));

    while (!q.empty()) {
        int r = q.top().r;
        int c = q.top().c;
        int t = q.top().t;
        q.pop();

        if (visited[r][c]) {
            continue;
        }

        if (r == N - 1 && c == M - 1) {
            return t;
        }

        visited[r][c] = 1;

        if (r > 0 && !visited[r - 1][c]) {
            q.push(Node(max(t, grid[r - 1][c]), r - 1, c));
        }
        if (c < M - 1 && !visited[r][c + 1]) {
            q.push(Node(max(t, grid[r][c + 1]), r, c + 1));
        }
        if (r < N - 1 && !visited[r + 1][c]) {
            q.push(Node(max(t, grid[r + 1][c]), r + 1, c));
        }
        if (c > 0 && !visited[r][c - 1]) {
            q.push(Node(max(t, grid[r][c - 1]), r, c - 1));
        }
    }

    return -1;
}

int main() {
    int N, M;
    cin>>N>>M;
    vector<vector<int>> grid (N, vector<int>(M));

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int x;
            cin>>x;

            grid[i][j]=x;
        }
    }

    cout<<swimInWater(grid);
    return 0;
}