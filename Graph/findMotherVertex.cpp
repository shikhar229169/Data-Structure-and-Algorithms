#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(vector<vector<int>>& graph, int src, vector<int>& visited) {
    visited[src]=1;

    for (int i: graph[src]) {
        if (!visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int findMotherVertex(vector<vector<int>>& connections, int vertices) {
    vector<vector<int>> graph(vertices);
    for (vector<int> i: connections) {
        graph[i[0]].push_back(i[1]);
    }

    int top;
    vector<int> visited(vertices, 0);

    for (int i=0; i<vertices; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited);
            top=i;
        }
    }

    for (int i=0; i<vertices; i++) {
        visited[i]=0;
    }

    dfs(graph, top, visited);

    for (int i=0; i<vertices; i++) {
        if (visited[i]==0) {
            return -1;
        }
    }

    return top;
}

int main(){
    int vertices, edges;
    cin>>vertices>>edges;
    vector<vector<int>> connections;

    for (int i=0; i<edges; i++) {
        int u, v;
        cin>>u>>v;

        connections.push_back({u, v});
    }

    cout<<findMotherVertex(connections, vertices);
    return 0;
}