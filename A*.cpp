#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

struct Node
{
    int id;
    double f,g; //f score and g score
    
};
struct Compare
{
    bool operator()(Node const & a, Node const & b) {
        return a.f > b.f; 
    }

}; 

double heuristic(pair<int,int> a, pair<int,int> b) {
    return sqrt(pow(a.first -b.first,2)+pow(a.second - b.second,2));
    
} 

void a_star(int starting_point,
            int ending_point,
            vector<vector<pair<int,int>>> & graph,
            vector<pair<int,int>> & coordinates
) {
    int lenght = graph.size();
    vector<double> g(lenght, 1e9);
    vector<int> parent(lenght, -1);

    priority_queue<Node, vector<Node>, Compare> open;

    g[starting_point] = 0; //first node

    open.push({starting_point,
               heuristic(coordinates[starting_point], coordinates[ending_point]),
               0});
    
    while(!open.empty()) {
        Node current = open.top();
        open.pop();

        int u = current.id;

        if(u == ending_point) {
           break;
        }

        for(auto [v,w] : graph[u]) {
            double tentative_g = g[u] + w;

            if(tentative_g < g[v]) {
                g[v] = tentative_g;
                parent[v] = u;
                double f = g[v] + heuristic(coordinates[v],coordinates[ending_point]);
                open.push({v,f,g[v]});

            }
        }

    }
    vector<int> path; 

    for(int v = ending_point; v!=-1; v = parent[v]) {
        path.push_back(v);     
    }
    reverse(path.begin(),path.end());

    cout << "yol: ";
    for(int v:path) cout << v << " ";
    cout << "\nToplam maliyet: " << g[ending_point] << endl;


}







int main() {
    int V = 5;
    vector<pair<int,int>> coordinates = {{0,0},{2,1},{4,2},{6,1},{3,4}};
    vector<vector<pair<int,int>>> graph(V);


    graph[0].push_back({1,2}); 
    graph[0].push_back({4,4});
    graph[1].push_back({2,2});
    graph[2].push_back({3,2});
    graph[3].push_back({4,3});
    graph[4].push_back({2,3});

    for(int u = 0; u< V; u++) { //graph'i yönsüz yap
        for(auto [v,w]: graph[u]) {
            graph[v].push_back({u,w});
        }
    }
   a_star(0,3,graph,coordinates);
    

    return 0;
}