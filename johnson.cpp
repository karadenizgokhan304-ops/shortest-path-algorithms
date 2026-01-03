#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;
const int INF = 1e9;

struct Edge {
    int u,v,w;
};

bool bellmanFord(int V, vector<Edge> & edges, vector<int> & h) {
    h.assign(V,INF);
    h[0] = 0;
    for(int i = 1; i < V; i++) {
        for(auto &e: edges) {
            if(h[e.u] != INF && h[e.u] + e.w < h[e.v]) {
                h[e.v] = h[e.u] + e.w;

            }
        }
    }
    for(auto & e: edges) {
        if(h[e.u] !=INF && h[e.u] + e.w < h[e.v]) {
            return false;
        }
    }
    return true;
}

vector<int> dijkstra(int source, vector<vector<pair<int,int>>> & graph) {
    int V = graph.size();
    vector<int> distance(V,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    distance[source] = 0;

    pq.push({0,source});

    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if(d > distance[u]) continue;

        for(auto [v,w] : graph[u]) {
            if(distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v],v});
            }
    }



   }
   return distance;
}

int main() {
    int V = 5;

    vector<Edge> edges = {{0,1,-1},{0,2,4},{1,2,3},
                          {1,3,2},{1,4,2},{3,2,5},
                          {3,1,1},{4,3,-3}
                      };

    vector<Edge> final_edges = edges;
    for(int i = 0;i < V;i++) {
        final_edges.push_back({0,i,0});
    }

    vector<int> h;

    if(!bellmanFord(V,final_edges,h)) {
         cout << "negative cycle occured!" << endl;
         return 0;
    }
    

    vector<vector<pair<int,int>>> graph(V);

    for(auto &e: edges) {
        int new_weight = e.w + h[e.u] - h[e.v];
        graph[e.u].push_back({e.v, new_weight});
    }

    cout << "shortest ways for each pairs: " << endl;

    for(int u = 0; u<V;u++) {
        vector<int> distance = dijkstra(u,graph);
        for(int v = 0; v<V; v++) {
            if(distance[v] == INF) {
                cout << "INF ";

            }
            else {
                cout << distance[v] - h[u] + h[v] << " ";
            }
        }
        cout << endl;
    }

    return 0;



}