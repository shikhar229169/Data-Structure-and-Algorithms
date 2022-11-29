#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cmp (vector<int> a, vector<int> b) {
    return a[2] < b[2];
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
    vertices++;
    int cost=0;
    vector<vector<int>> graph;

    for (int i=1; i<vertices; i++) {
        int cost;
        cin>>cost;

        graph.push_back({0, i, cost});
        
    }

    for (int i=0; i<edges; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;

        graph.push_back({u, v, wt});
    }

    sort(graph.begin(), graph.end(), cmp);

    int parent[vertices];
    int size[vertices];
    for (int i=0; i<vertices; i++) {
        parent[i]=i;
        size[i]=1;
    }

    for (int i=0; i<graph.size(); i++) {
        int u=graph[i][0];
        int v=graph[i][1];

        int res=makeUnion(u, v, parent, size);
        if (res) {
            cost+=graph[i][2];
        }
    }

    cout<<cost<<endl;
    return 0;
}