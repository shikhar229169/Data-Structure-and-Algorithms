#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// link to the problem
// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

class Edge {
    public:
        int nbr;
        int wt;
    
        Edge(int nbr, int wt) {
            this->nbr=nbr;
            this->wt=wt;
        }
};

int findMinPath(vector<vector<Edge>>& graph) {
    int vertices=graph.size();
    queue<Edge> q;
    
    int dist=10000;
    q.push(Edge(0, 10000));
    vector<int> visited(vertices, 0);
    
    while (!q.empty()) {
        Edge item=q.front();
        q.pop();
        
        if (visited[item.nbr]) {
            continue;
        }
        
        visited[item.nbr]=1;
        
        for (Edge edge: graph[item.nbr]) {
            dist=min(dist, edge.wt);
            if (!visited[edge.nbr]) {
                q.push(Edge(edge.nbr, edge.wt));
            }
        }
    }
    
    return dist;
}

int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<Edge>> graph(n);
    for (int i=0; i<roads.size(); i++) {
        graph[roads[i][0]-1].push_back(Edge(roads[i][1]-1, roads[i][2]));
        graph[roads[i][1]-1].push_back(Edge(roads[i][0]-1, roads[i][2]));
    }
    
    return findMinPath(graph);
}

int main(){
    int vertices, edges;                       // vertices are numbered from 1 to 'vertices'
    cin>>vertices>>edges;

    vector<vector<int>> roads;
    for (int i=0; i<edges; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;

        roads.push_back({u, v, wt});
    }

    cout<<minScore(vertices, roads)<<endl;
    return 0;
}

