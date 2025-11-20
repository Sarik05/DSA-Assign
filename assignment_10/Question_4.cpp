#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[100], rnk[100];

int findSet(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

bool unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a == b) return false;

    if (rnk[a] < rnk[b]) {
        parent[a] = b;
    } else if (rnk[b] < rnk[a]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        rnk[a]++;
    }
    return true;
}

void sortEdges(Edge e[], int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (e[j].w < e[i].w) {
                Edge temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Edge edges[100];

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }

    sortEdges(edges, E);

    int mstWt = 0;
    Edge mst[100];
    int idx = 0;

    for (int i = 0; i < E; i++) {
        if (unionSet(edges[i].u, edges[i].v)) {
            mst[idx++] = edges[i];
            mstWt += edges[i].w;
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 0; i < idx; i++) {
        cout << mst[i].u << " " << mst[i].v << " " << mst[i].w << endl;
    }

    cout << "Total weight: " << mstWt << endl;

    return 0;
}