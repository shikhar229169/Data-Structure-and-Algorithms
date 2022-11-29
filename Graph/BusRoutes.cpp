#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

// this is a brute force solution for this problem.
// optimized code will be done soon

int numBusesToDestination(vector<vector<int>>& routes, int src, int dest) {
    int buses=routes.size();
    map<int, vector<int>> fetchBus;

    for (int i=0; i<buses; i++) {
        for (int stop: routes[i]) {
            fetchBus[stop].push_back(i);
        }
    }

    map<int, int> stopsVisited;
    vector<int> busBoarded(buses, 0);

    queue<pair<int, int>> q;
    q.push({src, 0});

    while (!q.empty()) {
        int currStop=q.front().first;
        int seq=q.front().second;
        q.pop();

        if (currStop==dest) {
            return seq;
        }

        for (int busOptions: fetchBus[currStop]) {
            if (busBoarded[busOptions]) {
                continue;
            }

            for (int stop: routes[busOptions]) {
                if (!stopsVisited[stop]) {
                    q.push({stop, seq + 1});
                    stopsVisited[stop]=1;
                }
            }
            busBoarded[busOptions]=1;
        }
    }

    return -1;
}

int main(){
    int buses;
    cin>>buses;

    vector<vector<int>> routes;
    for (int i=0; i<buses; i++) {
        int stops;
        cin>>stops;
        vector<int> stopsList;
        for (int i=0; i<stops; i++) {
            int x;
            cin>>x;
            stopsList.push_back(x);
        }
        routes.push_back(stopsList);
    }

    int src, dest;
    cin>>src>>dest;

    cout<<numBusesToDestination(routes, src, dest)<<endl;

    return 0;
}