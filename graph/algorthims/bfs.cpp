#include <iostream>
#include <queue>

using namespace std;

class Graph {
public:
    int vertices; // Number of vertices
    int** adjMatrix; // Adjacency matrix for the graph

    Graph(int V) {
        vertices = V;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; ++i) {
            adjMatrix[i] = new int[V]();
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // If the graph is undirected
    }

    void BFS(int start) {
        bool* visited = new bool[vertices]();
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            // Visit all the adjacent nodes of the current node
            for (int i = 0; i < vertices; ++i) {
                if (adjMatrix[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        delete[] visited;
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS starting from node 0: ";
    g.BFS(0);

    return 0;
}
