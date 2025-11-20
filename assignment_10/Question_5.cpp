#include <iostream>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    int adj[100][100];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int key[100], parent[100];
    bool used[100];

    for (int i = 0; i < V; i++) {
        key[i] = 999999;
        parent[i] = -1;
        used[i] = false;
    }

    key[0] = 0;

    for (int k = 0; k < V - 1; k++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!used[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        used[u] = true;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !used[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " " << i << " " << key[i] << "\n";
        total += key[i];
    }

    cout << total;
    return 0;
}