// O(m*logn)

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) { 
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskalMST(vector <pair<int, iPair> > edges, int V) { 
    int parent[V];
    int rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sort(edges.begin(), edges.end());

    int mst_wt = 0;
    vector<pair<int, int> > result;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (find(parent, u) != find(parent, v)) {
            cout << u << " - " << v << endl;
            result.push_back({u, v});
            mst_wt += edges[i].first;
            unionSet(parent, rank, u, v);
        }
    }

    cout << "Weight of MST is " << mst_wt;
}

int main() {
    int V = 9, E = 14;
    vector<pair<int, iPair> > edges;

    edges.push_back({4, {0, 1}});
    edges.push_back({8, {0, 7}});
    edges.push_back({8, {1, 2}});
    edges.push_back({11, {1, 7}});
    edges.push_back({7, {2, 3}});
    edges.push_back({2, {2, 8}});
    edges.push_back({4, {2, 5}});
    edges.push_back({9, {3, 4}});
    edges.push_back({14, {3, 5}});
    edges.push_back({10, {4, 5}});
    edges.push_back({2, {5, 6}});
    edges.push_back({1, {6, 7}});
    edges.push_back({6, {6, 8}});
    edges.push_back({7, {7, 8}});

    cout << "Edges of MST are \n";
    kruskalMST(edges, V);

    return 0;
}
