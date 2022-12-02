#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// using for simplicity to denote that there is an edge to a nbr with weight 'wt'
class Edge {
    public:
        int src;
        int nbr;
        int wt;

        Edge (int src, int nbr, int wt) {
            this->src=src;
            this->nbr=nbr;
            this->wt=wt;
        }
};

// to store edges in priority_queue in asceding order by their weights
class cmp {
    public:
        bool operator() (Edge a, Edge b) {
            return a.wt > b.wt;
        }
};

void findMinimumSpanningTree(vector<vector<Edge>>& graph) {
    int vertices=graph.size();

    // we can start from any node to start our span, lets say we start with 0

    vector<int> visited(vertices, 0);
    priority_queue<Edge, vector<Edge>, cmp> q;
    int cost=0;
    q.push(Edge(0, -1, 0));          // considering that 0 is connected to an imaginary node via weight 0

    while (!q.empty()) {
        Edge edge = q.top();
        q.pop();

        if (visited[edge.src]) {
            continue;
        }

        visited[edge.src]=1;

        // initially we consider an imaginary node so we will not print for it
        if (edge.nbr!=-1) {
            cout<<"Connect "<<edge.src<<" with "<<edge.nbr<<" via weight "<<edge.wt<<endl;
            cost+=edge.wt;
        } 

        for (Edge i: graph[edge.src]) {
            if (!visited[i.nbr]) {
                q.push(Edge(i.nbr, edge.src, i.wt));
            }
        }
    }

    cout<<endl<<"Minimum cost obtained is "<<cost<<endl;
}

int main(){
    int vertices, edges;
    cin>>vertices>>edges;
    // considering that the vertices in the graph will be from 0 to (vertices-1)
    // also considering that the graph is connected, otherwise minimum spanning tree is not possible for that case

    vector<vector<Edge>> graph(vertices);

    for (int i=0; i<edges; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;

        // as it is an undirected graph, therefore through 'u' we can reach 'v' via weight 'wt' and vice-versa

        graph[u].push_back(Edge(u, v, wt));
        graph[v].push_back(Edge(v, u, wt));
    }

    findMinimumSpanningTree(graph);
    return 0;
}