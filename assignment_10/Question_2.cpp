#include <iostream>
#include <queue>
using namespace std;

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

    bool visited[100] = {false};
    queue<int> q;

    visited[src] = true;
    q.push(src);

    cout << "BFS traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
    return 0;
}