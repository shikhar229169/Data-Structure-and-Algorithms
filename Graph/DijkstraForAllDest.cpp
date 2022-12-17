#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Edge {
    public:
        int nbr;
        int wt;

        Edge(int nbr, int wt) {
            this->nbr=nbr;
            this->wt=wt;
        }
};

class cmp{
    public:
        bool operator()(Edge a, Edge b) {
            return a.wt > b.wt;
        }
};

vector<int> findDist(vector<vector<Edge>>& graph, int src) {
    int vertices=graph.size();
    priority_queue<Edge, vector<Edge>, cmp> q;
    vector<int> dist(vertices, INT_MAX);
    vector<int> visited(vertices, 0);

    q.push(Edge(src, 0));
    dist[src]=0;

    while (!q.empty()) {
        Edge node=q.top();
        q.pop();

        if (visited[node.nbr]) {
            continue;
        }

        visited[node.nbr]=1;

        for (Edge edge: graph[node.nbr]) {
            if (!visited[edge.nbr] && dist[edge.nbr]>(node.wt+edge.wt)) {
                dist[edge.nbr]=node.wt + edge.wt;
                q.push(Edge(edge.nbr, dist[edge.nbr]));
            }
        }
    }

    return dist;
}

int main(){
    int vertices, edges;
    cin>>vertices>>edges;
    
    vector<vector<Edge>> graph(vertices);    
    // if i->src, graph[i][0]->there is an edge between i and graph[i][0], 
    //graph[i][1]->weight of edge

    for (int i=0; i<edges; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;

        graph[u].push_back(Edge(v, wt));
        graph[v].push_back(Edge(u, wt));
    }

    int src;
    cin>>src;
    vector<int> dist=findDist(graph, src);

    for (int i=0; i<vertices; i++) {
        if (dist[i]==0) {
            continue;
        }
        cout<<i<<"- "<<dist[i]<<endl;
    }
    return 0;
}