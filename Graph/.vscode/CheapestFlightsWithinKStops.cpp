#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// needs improvement

class Edge {
public:
    int nbr;
    int wt;

    Edge(int nbr, int wt) {
        this->nbr=nbr;
        this->wt=wt;
    }
};

class Node {
public:
    int curr;
    int lvl;
    int wsf;
    string psf;

    Node(int curr, int lvl, int wsf, string psf) {
        this->curr=curr;
        this->lvl=lvl;
        this->wsf=wsf;
        this->psf=psf;
    }
};

class cmp
{
public:
    bool operator() (Node first, Node second)
    {
        return first.wsf > second.wsf;
    }
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<Edge>> Flights(n);

    for (vector<int> v: flights) {
        Flights[v[0]].push_back(Edge(v[1], v[2]));
    }

    int price=0;
    int travelled[n]={0};
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push(Node(src, 0, 0, "0"));

    while (!pq.empty()) {
        Node node=pq.top();
        pq.pop();

        if (travelled[node.curr]) {
            continue;
        }
        travelled[node.curr]=1;

        
        if (node.curr==dst) {
            //cout<<node.wsf<<endl;
            //cout<<node.lvl<<endl;
            cout<<node.psf<<endl;
            return node.wsf;
        }
        
        // if (node.lvl==k+1) {
        //     continue;
        // }

        for (Edge i: Flights[node.curr]) {
            if (!travelled[i.nbr]) {
                pq.push(Node(i.nbr, node.lvl + 1, node.wsf + i.wt, node.psf+(char)(i.nbr+'0')));
            }
        }
    }

    return -1;
}

int main(){
    vector<vector<int>> flights;

    int n, src, dst, k;
    cin>>n;
    int edges;
    cin>>edges;
    for (int i=0; i<edges; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;
        flights.push_back({u, v, wt});
    }
    cin>>src>>dst>>k;
    cout<<findCheapestPrice(n, flights, src, dst, k);
    return 0;
}











/*
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

class Node {
public:
    int curr;
    int lvl;
    int wsf;

    Node(int curr, int lvl, int wsf) {
        this->curr=curr;
        this->lvl=lvl;
        this->wsf=wsf;
    }
};

class cmp
{
public:
    bool operator() (Node first, Node second)
    {
        return first.wsf > second.wsf;
    }
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<Edge>> Flights(n);

    for (vector<int> v: flights) {
        Flights[v[0]].push_back(Edge(v[1], v[2]));
    }

    int price=0;
    int travelled[n]={0};
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push(Node(src, 0, 0));

    while (!pq.empty()) {
        Node node=pq.top();
        pq.pop();

        if (travelled[node.curr]) {
            continue;
        }
        travelled[node.curr]=1;

        
        if (node.curr==dst) {
            //cout<<node.wsf<<endl;
            cout<<node.lvl<<endl;
            return node.wsf;
        }
        
        if (node.lvl==k+1) {
            continue;
        }

        for (Edge i: Flights[node.curr]) {
            if (!travelled[i.nbr]) {
                pq.push(Node(i.nbr, node.lvl + 1, node.wsf + i.wt));
            }
        }
    }

    return -1;
}

int main(){
    vector<vector<int>> flights;

    int n, src, dst, k;
    cin>>n;
    int edges;
    cin>>edges;
    for (int i=0; i<edges; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;
        flights.push_back({u, v, wt});
    }
    cin>>src>>dst>>k;
    cout<<findCheapestPrice(n, flights, src, dst, k);
    return 0;
}
*/