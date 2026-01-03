#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>

using namespace std;
void  build_graph(vector<vector<int>> & graph,list<int> & u, list<int> & to ) {
    auto u_first_it = u.begin();
    auto to_first_it = to.begin();
    for(size_t i = 0; i< u.size(); i++) {
        graph[*u_first_it].push_back(*to_first_it);
        graph[*to_first_it].push_back(*u_first_it);
        u_first_it++;
        to_first_it++;


    }
    

}

void dfs(int u, vector<vector<int>> & graph, vector<bool> & visited) {
    visited[u] = true;
    cout << u << " ";
    for(int v: graph[u])  {
    
        if(!visited[v]) {
            dfs(v,graph,visited);
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>>  graph(V);
    

    list<int> u = {0,0,1,1};
    list<int> to = {1,2,3,4};
    build_graph(graph,u,to);
    vector<bool> visited(V,false);

    cout << "dfs traversal: " << endl;
    dfs(0,graph,visited);
    return 0;

    
}