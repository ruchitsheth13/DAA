#include <bits/stdc++.h>
using namespace std;
#define V 5

void dijkstra(int G[][V], int src, int dist[]) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int min_dist = INT_MAX, min_index;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= min_dist) {
                min_dist = dist[v];
                min_index = v;
            }
        }
        visited[min_index] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && G[min_index][v] && dist[min_index] + G[min_index][v] < dist[v]) {
                dist[v] = dist[min_index] + G[min_index][v];
            }
        }
    }
}

int main() {
    int G[V][V] = {{0, 1, 0, 3, 10},
                   {1, 0, 5, 0, 0},
                   {0, 5, 0, 2, 1},
                   {3, 0, 2, 0, 6},
                   {10, 0, 1, 6, 0}};
    int dist[V];
    int src = 0;
    dijkstra(G, src, dist);
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << "        " << dist[i] << endl;
    return 0;
}
