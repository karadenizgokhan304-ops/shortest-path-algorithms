#include <bits/stdc++.h>
#include <iostream>
#include <vector>

const int INF = 1e9;

using namespace std;


int main() {
    int V = 4;
 
    vector<vector<int>> dist(V, vector<int>(V,INF));

    for(int i=0;i<V;i++) {
        dist[i][i] = 0;
    }

    dist[0][1] = 5;
    dist[1][0] = 5;
    dist[0][3] = 10;
    dist[1][2] = 3;
    dist[2][3] = 1;


    for(int k = 0; k<V;k++) {
        for(int i= 0; i<V;i++) {
            for(int j = 0; j<V;j++) {
                if(dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);

                }
            }

        }
    }

    cout << "en kisa mesafeler matrisi:" << endl;
    for(int i = 0; i<V;i++) {
        for(int j =0;j<V;j++) {
            if(dist[i][j] == INF) {
                cout << "INF ";
            }
            else{
                cout << dist[i][j] << " ";

            }
            
        }
        cout << endl;

    }



    return 0;
}