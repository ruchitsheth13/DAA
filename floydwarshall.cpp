// O(n^3)

#include<bits/stdc++.h>
using namespace std;

#define V 4
#define inf 99999

void printSolution(int dist[][V]) {
    cout << "The following matrix shows the shortest path b/w every pair of vertices: \n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == inf)
                cout << "inf" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void floydwarshall(int dist[][V]) {
    int i, j, k;
    for(k = 0; k < V; k++) {
        for(i = 0; i < V; i++) {
            for(j = 0; j < V; j++) {
                if(dist[i][j] > (dist[i][k]) + (dist[k][j]) && (dist[i][k] != inf && dist[k][j] != inf))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }    
    printSolution(dist);
}

int main() {
    int G[V][V] = {
        { 0, 5, inf, 10 },
        { inf, 0, 3, inf },
        { inf, inf, 0, 1 },
        { inf, inf, inf, 0 }
    };
    floydwarshall(G);
    return 0;
}
