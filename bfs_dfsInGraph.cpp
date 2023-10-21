#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Graph
{
private:
    int vertices;
    vector<vector<int>> adjList;
public:
    Graph(int V)
    {
        vertices = V;
        adjList.resize(V);
    }
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For an undirected graph
    }
    void BFS(int start)
    {
        vector<bool> visited(vertices, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        cout << "BFS traversal starting from vertex " << start << ": ";
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";
            for (int neighbor : adjList[vertex])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }
    void DFS(int start)
    {
        vector<bool> visited(vertices, false);
        stack<int> s;
        s.push(start);
        cout << "DFS traversal starting from vertex " << start << ": ";
        while (!s.empty())
        {
            int vertex = s.top();
            s.pop();
            if (!visited[vertex])
            {
                cout << vertex << " ";
                visited[vertex] = true;
            }
            for (int neighbor : adjList[vertex])
            {
                if (!visited[neighbor])
                {
                    s.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};
int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    Graph graph(V);
    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    int choice;
    int startVertex;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Breadth-First Search (BFS)\n";
        cout << "2. Depth-First Search (DFS)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the starting vertex for BFS: ";
            cin >> startVertex;
            graph.BFS(startVertex);
            break;
        case 2:
            cout << "Enter the starting vertex for DFS: ";
            cin >> startVertex;
            graph.DFS(startVertex);
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}