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
    }

    int src;
    cin >> src;

    const int INF = 1000000000;

    int dist[100];
    bool used[100];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        used[i] = false;
    }

    dist[src] = 0;

    for (int k = 0; k < V; k++) {
        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!used[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        used[u] = true;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << ": INF\n";
        else
            cout << i << ": " << dist[i] << "\n";
    }

    return 0;
}