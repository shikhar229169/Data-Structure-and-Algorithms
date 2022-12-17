#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> FloydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int> (V, 4000));
    for (vector<int> i: graph) {
        dist[i[0]][i[1]]=i[2];
    }
    for (int i=0; i<V; i++) {
        dist[i][i]=0;
    }

    for (int k=0; k<V; k++) {
        for (int i=0; i<V; i++) {
            if (i==k || dist[i][k]==4000) {
                continue;
            }
            for (int j=0; j<V; j++) {
                dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

int main(){
    int vertices, edges;
    cin>>vertices>>edges;
    vector<vector<int>> graph;

    for (int i=0; i<edges; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;
        graph.push_back({u, v, wt});
    }

    vector<vector<int>> shortestWeightedPath = FloydWarshall(graph, vertices);

    for (auto i: shortestWeightedPath) {
        for (auto j: i) {
            if (j==4000) {
                cout<<"I"<<" ";
                continue;
            }
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}