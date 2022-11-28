#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Edge {
public:
    int src;
    int nbr;
    int wt;

    Edge() {

    }

    Edge(int src, int nbr, int wt) {
        this->src=src;
        this->nbr=nbr;
        this->wt=wt;
    }
};

void AllPaths(vector<vector<Edge>>& Graph, int src, int vertices, int visited[], vector<int> p) {
    if (p.size()==vertices-1 || (p==vertices.size() && src==p[0])) {
        p.push_back(src);
        for (int i : p) {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }

    visited[src]=1;
    p.push_back(src);

    for (Edge i : Graph[src]) {
        if (!visited[i.nbr]) {
            AllPaths(Graph, i.nbr, vertices, visited, p);
        }
    }

    visited[src]=0;                       // backtracking
}


int main(){
    int vertices;
    cin>>vertices;
    
    int edges;
    cin>>edges;
    
    vector<vector<Edge>> Graph(vertices);

    for (int i=0; i<edges; i++) {
        int src, nbr, wt;
        cin>>src>>nbr>>wt;

        Graph[src].push_back(Edge(src, nbr, wt));
        Graph[nbr].push_back(Edge(nbr, src, wt));
    }

    int src;
    cin>>src;
    
    int visited[vertices]={0};
    
    AllPaths(Graph, src, vertices, visited, {});
    return 0;
}