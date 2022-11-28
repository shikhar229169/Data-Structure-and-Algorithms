#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// minimum spanning tree by Kruskal's Algorithm 
// here disjoint set union is used to find if there is a loop while placing an edge on the basis of concept of connected componenets

int findParent(int node, int parent[]) {
    if (parent[node]==node) {
        return node;
    }
    return parent[node]=findParent(parent[node], parent);
}

int makeUnion(int node1, int node2, int parent[], int size[]) {
    int par1=findParent(node1, parent);
    int par2=findParent(node2, parent);

    if (par1==par2) {
        return false;
    }

    if (size[par1]>size[par2]) {
        parent[par2]=par1;
        size[par1]+=size[par2];
    }
    else {
        parent[par1]=par2;
        size[par2]+=size[par1];
    }

    return true;
}

void findMST(vector<vector<int>>& graph, int parent[], int size[]) {
    int cost=0;
    for (vector<int> node: graph) {
        int v1=node[0];
        int v2=node[1];

        if (makeUnion(v1, v2, parent, size)) {
            cout<<v1<<"-"<<v2<<"@"<<node[2]<<endl;
            cost+=node[2];
        }
    }
    cout<<cost<<endl;
}

int cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
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

    sort(graph.begin(), graph.end(), cmp);

    int parent[vertices];
    int size[vertices];
    for (int i=0; i<vertices; i++) {
        parent[i]=i;
        size[i]=1;
    }

    findMST(graph, parent, size);
    return 0;
}