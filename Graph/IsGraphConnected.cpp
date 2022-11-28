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

void findConnectedComponents(vector<vector<Edge>>& Graph, int start, int visited[], int& ct) {
    visited[start]=1;
    ct++;

    for (Edge edge : Graph[start]) {
        if (!visited[edge.nbr]) {
            findConnectedComponents(Graph, edge.nbr, visited, ct);
        }
    }
}

int main(){
    int vertices;
    printf("Enter vertices: ");
    cin>>vertices;
    
    int edges;
    printf("Enter edges: ");
    cin>>edges;
    
    vector<vector<Edge>> Graph(vertices);

    for (int i=0; i<edges; i++) {
        int src, nbr, wt;
        cin>>src>>nbr>>wt;

        Graph[src].push_back(Edge(src, nbr, wt));
        Graph[nbr].push_back(Edge(nbr, src, wt));
    }

    int visited[vertices]={0};

    int ct=0;
    findConnectedComponents(Graph, 0, visited, ct);
    if (ct==vertices) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }

    
    return 0;
}