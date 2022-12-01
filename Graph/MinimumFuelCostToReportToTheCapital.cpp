#include<iostream>
#include<vector>
using namespace std;

// link to the problem
//https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

class Node {
    public:
        int num;
        int cars;
        long long cost;

        Node (int num, int cars, long long cost) {
            this->num=num;
            this->cars=cars;
            this->cost=cost;
        }
};

Node findCost(vector<vector<int>>& graph, int src, vector<int>& visited, int seats) {
    visited[src]=1;

    Node node=Node(0, 0, 0);

    for (int edge: graph[src]) {
        if (!visited[edge]) {
            Node subNode=findCost(graph, edge, visited, seats);

            node.cost+=subNode.cost;
            node.cars+=subNode.cars;
            node.num+=subNode.num;
        }
    }

    int cars=node.cars;
    int pep=node.num+1;

    cars=pep/seats;
    if (pep % seats) {
        cars++;
    }

    node.num=pep;
    node.cars=cars;
    node.cost+=cars;

    return node;
}

long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    vector<vector<int>> graph(roads.size()+1);

    for (vector<int> i: roads) {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }

    long long cost=0;
    vector<int> visited (roads.size()+1, 0);
    visited[0]=1;
    for (int edge: graph[0]) {
        Node node=findCost(graph, edge, visited, seats);
        cost+=node.cost;
    }

    return cost;
}

int main(){
    int edges;
    cin>>edges;

    vector<vector<int>> road;
    for (int i=0; i<edges; i++) {
        int u, v;
        cin>>u>>v;
        road.push_back({u, v});
    }

    int seats;
    cin>>seats;

    cout<<minimumFuelCost(road, seats)<<endl;
    return 0;
}