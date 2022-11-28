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

void findAllPaths(vector<vector<Edge>>& Graph, int src, int dest, int visited[], vector<int> p) {
    if (src==dest) {
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
            findAllPaths(Graph, i.nbr, dest, visited, p);
        }
    }

    visited[src]=0;                       // backtracking
}

vector<pair<int, vector<int>>> returnAllPaths(vector<vector<Edge>>& Graph, int src, int dest, int visited[], int weight) {
    vector<pair<int, vector<int>>> ans;
    if (src==dest) {
        ans.push_back({weight, {src}});
        return ans;
    }

    visited[src]=1;

    for (Edge edge : Graph[src]) {
        if (!visited[edge.nbr]) {
            vector<pair<int, vector<int>>> subAns=returnAllPaths(Graph, edge.nbr, dest, visited, weight + edge.wt);
            for (pair<int, vector<int>> path: subAns) {
                vector<int> temp;
                temp.push_back(src);
                for (int i: path.second) {
                    temp.push_back(i);
                }
                ans.push_back({path.first, temp});
            }
        }
    }
    visited[src]=0;                       // backtracking

    return ans;
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

    int src, dest;
    cin>>src>>dest;
    int criteria, K;
    cin>>criteria>>K;
    int visited[vertices]={0};
    
    vector<pair<int, vector<int>>> paths=returnAllPaths(Graph, src, dest, visited, 0);

    sort(paths.begin(), paths.end());

    cout<<"Smallest Path = ";
    for (int i: paths[0].second) {
        cout<<i;
    }
    cout<<"@"<<paths[0].first<<endl;

    cout<<"Largest Path = ";
    for (int i: paths[paths.size()-1].second) {
        cout<<i;
    }
    cout<<"@"<<paths[paths.size()-1].first<<endl;

    vector<int> Keq;
    vector<int> less;
    vector<int> great;
    int l, g;

    for (pair<int, vector<int>> i: paths) {
        if (i.first<criteria) {
            less=i.second;
            l=i.first;
        }
        if (i.first>criteria) {
            great=i.second;
            g=i.first;
            break;
        }
    }

    cout<<"Just Larger Path than"<<criteria<<" = ";
    for (int i: great) {
        cout<<i;
    }
    cout<<"@"<<g<<endl;

    cout<<"Just Smaller Path than"<<criteria<<" = ";
    for (int i: less) {
        cout<<i;
    }
    cout<<"@"<<l<<endl;

    cout<<K<<"th largest path = ";
    for (int i : paths[paths.size()-K].second) {
        cout<<i;
    }
    cout<<"@"<<(paths[paths.size()-K].first)<<endl;
    return 0;
}