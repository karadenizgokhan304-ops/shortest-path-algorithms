#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <sstream>
#include <list>
using namespace std;

static int V = 5;
static vector<vector<int>> graph(V);


void  build_graph(list<int> & u, list<int> & to ) {
    auto u_first_it = u.begin();
    auto to_first_it = to.begin();
    for(size_t i = 0; i< u.size(); i++) {
        graph[*u_first_it++].push_back(*to_first_it++);
    }
    


}

int main() {
    

    //ağırlıksız-yönsüz graph 
    list <int> u = {0,1,0,2,1,3,2,4};
    list <int> to = {1,0,2,0,3,1,4,2};
    build_graph(u,to);

    int start = 0;

    vector<bool> visited(V, false);
    vector<int> distance(V,-1);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while(!q.empty()) {
       int u = q.front();
       q.pop();
       for(int v: graph[u]) {
        if(!visited[v]) {
            visited[v] = true;
            distance[v] = distance[u] + 1;
            q.push(v);
        }

       }

    }
    stringstream ss;
    cout << "en kisa mesafeler: " << endl;
    for(int i = 0; i<V;i++) {
        ss << start << " -> " << i << " = " << distance[i] << "\n";
        cout << ss.str();

        ss.clear();
        ss.str("");



    }


}