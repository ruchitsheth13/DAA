// O(m*logn)

#include<bits/stdc++.h>
using namespace std;
#define inf 999999
#define max 10

int G[max][max] = {
    {0, 19, 8}, 
    {21, 0, 13},
    {15, 18, 0}
};
int S[max][max], n;

int prims() {
    int C[max][max];
    int u, v, min_dist, dist[max], from[max];
    int visited[max], ne, i, min_cost, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            if(G[i][j] == 0)
                C[i][j] = inf;
            else
                C[i][j] = G[i][j];
            S[i][j] = 0;
        }
    dist[0] = 0;
    visited[0] = 1;
    for(i = 1; i < n; i++) {
        dist[i] = C[0][i];
        from[i] = 0;
        visited[i] = 0;
    }
    min_cost = 0; //cost of spanning tree
    ne = n-1; //no. of edges to be added
    while(ne > 0) {
        min_dist = inf;
        for(i = 1; i < n; i++)
            if(visited[i] == 0 && dist[i] < min_dist) {
                v = i;
                min_dist = dist[i];
            }
        u = from[v];
        S[u][v] = dist[v];
        S[v][u] = dist[v];
        ne--;
        visited[v]=1;
        for(i = 1; i < n; i++)
            if(visited[i] == 0 && C[i][v] < dist[i]) {
                dist[i] = C[i][v];
                from[i] = v;
            }
        min_cost = min_cost + C[u][v];
    }
    return(min_cost);
}

int main() {
    int i, j, cost;
    n = 3;
    cost = prims();
    cout << "Spanning Tree";
    for(int i = 0; i < n; i++) {
        cout << endl;
        for(int j = 0; j < n; j++) {
            cout << S[i][j] << " ";
        }
    }
    cout << "\nMinimum cost: " << cost;
    return 0;
}
