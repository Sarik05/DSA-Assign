#include <iostream>
using namespace std;

void dfs(int u, int adj[100][100], bool vis[], int V) {
    vis[u] = true;
    cout << u << " ";

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && !vis[v]) {
            dfs(v, adj, vis, V);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int adj[100][100] = {0};

    cout << "Enter edges (u v) 0-based:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    bool vis[100] = {false};

    cout << "DFS traversal: ";
    dfs(src, adj, vis, V);

    cout << endl;
    return 0;
}