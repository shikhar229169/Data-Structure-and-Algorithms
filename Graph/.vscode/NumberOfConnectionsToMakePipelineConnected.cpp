#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// will do it with disjoint set union

class Edge {
    public:
        int src;
        int nbr;

        Edge(int src, int nbr) {
            this->src=src;
            this->nbr=nbr;
        }
};

int bfsEdges(vector<vector<Edge>>& graph, int src, int visited[]) {
    queue<int> q;
    q.push(src);
    int vtces=0;
    int edges=0;

    while (!q.empty()) {
        int node=q.front();
        q.pop();

        if (visited[node]) {
            continue;
        }

        visited[node]=1;
        vtces++;

        for (Edge i: graph[node]) {
            if (!visited[i.nbr]) {
                q.push(i.nbr);
                edges++;
            }
        }
    }

    return edges-vtces+1;
}

int findParent(int v, int parent[]) {
    if (parent[v]==v) {
        return v;
    }

    return parent[v]=findParent(parent[v], parent);
}

int makeUnion(int v1, int v2, int parent[], int size[]) {
    int par1=findParent(v1, parent);
    int par2=findParent(v2, parent);

    if (par1==par2) {
        return 0;
    }

    if (size[par1]>size[par2]) {
        parent[par2]=par1;
        size[par1]+=size[par2];
    }
    else {
        parent[par1]=par2;
        size[par2]+=size[par1];
    }

    return 1;
}

int main(){
    int vertices, edges;
    cin>>vertices>>edges;
    vector<vector<int>> graph;

    for (int i=0; i<edges; i++) {
        int u, v;
        cin>>u>>v;
        graph.push_back({u, v});
    }

    int components=0;
    int extraEdges=0;
    int parent[vertices];
    int size[vertices];
    for (int i=0; i<vertices; i++) {
        parent[i]=i;
        size[i]=1;
    }

    for (int i=0; i<edges; i++) {
        int u=graph[i][0];
        int v=graph[i][1];

        int res=makeUnion(u, v, parent, size);
        if (!res) {
            extraEdges++;
        }
    }

    for (int i=0; i<vertices; i++) {
        if (parent[i]==i) {
            components++;
        }
    }

    if (extraEdges>=components-1) {
        cout<<components-1<<endl;
    }
    else {
        cout<<-1<<endl;
    }

    // int componenets=0;
    // int extraEdges=0;
    // int visited[vertices]={0};

    // for (int i=0; i<vertices; i++) {
    //     if (!visited[i]) {
    //         extraEdges+=bfsEdges(graph, i, visited);
    //         componenets++;
    //     }
    // }
    // cout<<extraEdges<<" "<<componenets-1<<endl;
    // if (extraEdges>=componenets-1) {
    //     cout<<componenets-1<<endl;
    // }
    // else {
    //     cout<<-1<<endl;
    // }
    return 0;
}