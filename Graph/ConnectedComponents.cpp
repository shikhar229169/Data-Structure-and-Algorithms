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

void findConnectedComponents(vector<vector<Edge>>& Graph, int start, vector<int>& ans, int visited[]) {
    ans.push_back(start);
    visited[start]=1;

    for (Edge edge : Graph[start]) {
        if (!visited[edge.nbr]) {
            findConnectedComponents(Graph, edge.nbr, ans, visited);
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
    vector<vector<int>> ans;

    for (int i=0; i<vertices; i++) {
        vector<int> subAns;
        if (!visited[i]) {
            findConnectedComponents(Graph, i, subAns, visited);
            ans.push_back(subAns);
        }
    }


    for (vector<int> i: ans) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}