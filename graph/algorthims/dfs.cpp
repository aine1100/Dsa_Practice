#include <iostream>

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

    void DFS(int start) {
        bool* visited = new bool[vertices]();
        DFSUtil(start, visited);
        delete[] visited;
        cout << endl;
    }

private:
    void DFSUtil(int node, bool* visited) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "DFS starting from node 0: ";
    g.DFS(0);

    return 0;
}
