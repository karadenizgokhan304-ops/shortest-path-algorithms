#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <sstream>
using namespace std;

struct Edge
{
    int u,v,w;
};



int main() {
    int V = 5;
    int E = 8;

    vector<Edge> edges = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}

    };

    int start = 0;

    vector<int> distance(V,INT_MAX);

    distance[start] = 0;

    for(int i = 1; i <= V-1; i++) {
        for(auto e: edges) {
            if(distance[e.u] != INT_MAX &&
               distance[e.u] + e.w < distance[e.v]) { 
                distance[e.v] = distance[e.u] + e.w;
               }
        }

    }

    for(auto e: edges) {
            if(distance[e.u] != INT_MAX &&
               distance[e.u] + e.w < distance[e.v]) { 
                cout << "negatif ağirlikli döngü var." << endl;
                return 0;
                
               }
        }
    stringstream ss;
   
    cout << "en kisa mesafeler:\n";
    for(int i = 0;i<V;i++) {
        ss << start << " -> " << i << " = " ;
        if(distance[i] == INT_MAX) {
            ss << "INF\n";
        }
        else {
            ss << distance[i] << "\n";
        }
        cout << ss.str();
        ss.clear();
        ss.str("");
    } 




    return 0;
}