#include <iostream>
#include <vector>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
    void dijkstra(int start);
};
Graph::Graph(int vertices) : V(vertices) {
    adj.resize(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i)
        adj[i][i] = 0;
}
void Graph::addEdge(int u, int v, int weight) {
    adj[u][v] = weight;
}
void Graph::dijkstra(int start) {
    vector<int> dist(V, INF);
    dist[start] = 0;
    bool visited[V] = {false};
    for (int i = 0; i < V; ++i) {
        int u = -1;
        for (int j = 0; j < V; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }
        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (adj[u][v] != INF) {
                if (dist[u] + adj[u][v] < dist[v])
                    dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        cout << "Shortest distance from " << start << " to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    Graph g(vertices);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add an edge\n";
        cout << "2. Find shortest paths using Dijkstra's algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                int u, v, weight;
                cout << "Enter edge (source, destination, weight): ";
                if (cin >> u >> v >> weight) {
                    g.addEdge(u, v, weight);
                } else {
                    cout << "Invalid input. Please enter integers for source, destination, and weight." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;

            case 2:
                int start;
                cout << "Enter the starting vertex: ";
                if (cin >> start && start >= 0 && start < vertices) {
                    g.dijkstra(start);
                } else {
                    cout << "Invalid input. Please enter a valid starting vertex." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}