#include <iostream>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    int adj[100][100] = {0};

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    int choice;
    do {
        cout << "\n1. Display adjacency matrix\n";
        cout << "2. Degree of a vertex (undirected)\n";
        cout << "3. In-degree\n";
        cout << "4. Out-degree\n";
        cout << "5. Adjacent vertices\n";
        cout << "6. Number of edges\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    cout << adj[i][j] << " ";
                }
                cout << "\n";
            }
        }

        else if (choice == 2) {
            int v, d = 0;
            cout << "Enter vertex: ";
            cin >> v;
            for (int i = 0; i < V; i++) {
                d += adj[v][i];
                d += adj[i][v];
            }
            cout << d << "\n";
        }

        else if (choice == 3) {
            int v, d = 0;
            cout << "Enter vertex: ";
            cin >> v;
            for (int i = 0; i < V; i++) d += adj[i][v];
            cout << d << "\n";
        }

        else if (choice == 4) {
            int v, d = 0;
            cout << "Enter vertex: ";
            cin >> v;
            for (int i = 0; i < V; i++) d += adj[v][i];
            cout << d << "\n";
        }

        else if (choice == 5) {
            int v;
            cout << "Enter vertex: ";
            cin >> v;
            for (int i = 0; i < V; i++) {
                if (adj[v][i] == 1) cout << i << " ";
            }
            cout << "\n";
        }

        else if (choice == 6) {
            int c = 0;
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) c += adj[i][j];
            }
            cout << c << "\n";
        }

    } while (choice != 7);

    return 0;
}