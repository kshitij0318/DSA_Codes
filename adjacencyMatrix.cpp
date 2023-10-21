#include <iostream>
#include <vector>
using namespace std;
void printAdjacencyMatrix(const vector<vector<int>>& graph) {
    int V = graph.size();
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
void addEdge(vector<vector<int>>& graph, int u, int v, int weight) {
    if (u < 0 || v < 0 || u >= graph.size() || v >= graph.size()) {
        cout << "Invalid vertex. Vertex must be between 0 and " << graph.size() - 1 << endl;
        return;
    }   
    graph[u][v] = weight;
    graph[v][u] = weight;
}
int main() {
    int V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;   
    // Initialize the adjacency matrix with all zeros
    vector<vector<int>> graph(V, vector<int>(V, 0));
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add an edge\n";
        cout << "2. Print adjacency matrix\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int u, v, weight;
                cout << "Enter edge (u v weight): ";
                cin >> u >> v >> weight;
                addEdge(graph, u, v, weight);
                break;
            }
            case 2: {
                cout << "Adjacency Matrix:\n";
                printAdjacencyMatrix(graph);
                break;
            }
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);
    return 0;
}
