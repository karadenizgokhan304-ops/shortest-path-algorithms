#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void dijkstra(int start, vector<vector<pair<int,int>>>& graph) {
    int len = graph.size();
    vector<int> distance(len,INT_MAX); // [INT_MAX,INT_MAX ...]

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq; //önceliğimizi berlirlememiz için önemli en uzak mesafeyi listenin sonuna iter.
    distance[start] = 0;
    pq.push({0,start});

    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop(); 
        if(d > distance[u]) continue;

        for(auto [v,w]: graph[u]) {
            if(distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v],v});



            }
        }
    }
    for (int d: distance) cout << d << " ";




}

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> graph(V);
    graph[0].push_back({1,10}); // 0.Node, 1.Node'a 10 birim uzaklıkta.
    graph[0].push_back({4,3});
    graph[1].push_back({2,2});
    graph[1].push_back({4,4});
    graph[2].push_back({3,9});
    graph[3].push_back({2,7});
    graph[4].push_back({1,1});
    graph[4].push_back({2,8});
    graph[4].push_back({3,2});
    
       

    dijkstra(0,graph);  //out: 0 4 6 5 3 : 1.node'a en kısa yol 0 birim, 1.node'a 4, ...
    return 0;
}