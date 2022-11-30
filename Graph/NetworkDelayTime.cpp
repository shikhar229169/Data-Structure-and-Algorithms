#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// https://leetcode.com/problems/network-delay-time/

class Node {
    public:
        int vtx;
        int delay;

        Node (int vtx, int delay) {
            this->vtx=vtx;
            this->delay=delay;
        }
};

struct cmp {
    bool operator()(Node& n1, Node& n2) {
        return n1.delay > n2.delay;
    }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<Node>> graph(n+1);
    for (vector<int> node: times) {
        graph[node[0]].push_back({node[1], node[2]});
    }
    
    vector<int> visited(n+1, 0);
    vector<int> dist(n+1, 100000);

    priority_queue<Node, vector<Node>, cmp> q;
    q.push(Node(k, 0));
    dist[k]=0;
    
    while (!q.empty()) {
        Node node=q.top();
        q.pop();

        if (visited[node.vtx]) {
            continue;
        }
        visited[node.vtx]=1;

        for (Node childNode: graph[node.vtx]) {
            if ((node.delay + childNode.delay) < dist[childNode.vtx]) {
                dist[childNode.vtx]=node.delay + childNode.delay;
                q.push({childNode.vtx, dist[childNode.vtx]});
            }
        }
    }

    int maxDelay=0;
    for (int i=1; i<=n; i++) {
        if (dist[i]==100000) {
            return -1;
        }
        maxDelay=max(maxDelay, dist[i]);
    }

    return maxDelay;

}

int main(){
    int vertices, edges;
    cin>>vertices>>edges;

    vector<vector<int>> times;

    for (int i=0; i<edges; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        times.push_back({u, v, wt});
    }

    int src;
    cin>>src;
    
    cout<<networkDelayTime(times, 4, 2);
    return 0;
}