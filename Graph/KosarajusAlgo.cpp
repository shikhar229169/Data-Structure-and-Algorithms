#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(vector<vector<int>>& graph, int src, vector<int>& visited, stack<int>& st) {
    visited[src]=1;

    for (int i: graph[src]) {
        if (!visited[i]) {
            dfs(graph, i, visited, st);
        }
    }

    st.push(src);
}

void findAllElements(vector<vector<int>>& revGraph, int src, vector<int>& visited) {
    visited[src]=2;

    cout<<src<<" ";

    for (int i: revGraph[src]) {
        if (visited[i]!=2) {
            findAllElements(revGraph, i, visited);
        }
    }
}

int findStronglyConnectedComponents(vector<vector<int>>& connections, int vertices) {
    vector<vector<int>> graph(vertices);
    for (vector<int> i: connections) {
        graph[i[0]].push_back(i[1]);
    }

    stack<int> st;
    vector<int> visited(vertices, 0);

    for (int i=0; i<vertices; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, st);
        }
    }

    vector<vector<int>> revGraph(vertices);
    for (vector<int> i: connections) {
        revGraph[i[1]].push_back(i[0]);
    }

    int ct=0;

    while(!st.empty()) {
        int item=st.top();
        st.pop();

        if (visited[item]==2) {
            continue;
        }

        findAllElements(revGraph, item, visited);
        ct++;
        cout<<endl;
    }

    return ct;
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

    int Count=findStronglyConnectedComponents(connections, vertices);
    cout<<"Total number of strognly connected components are: "<<Count<<endl;
    return 0;
}