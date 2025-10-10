//Пример 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) : vertices(v), adjList(v) {}
    
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        cout << "BFS: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    
    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    
    g.printGraph();
    g.BFS(0);
    
    return 0;
}
//Пример 2
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class GraphMatrix {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int v) : vertices(v), adjMatrix(v, vector<int>(v, 0)) {}
    
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        stack<int> s;
        
        s.push(start);
        
        cout << "DFS: ";
        while (!s.empty()) {
            int current = s.top();
            s.pop();
            
            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";
                
                for (int i = vertices - 1; i >= 0; i--) {
                    if (adjMatrix[current][i] == 1 && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }
        cout << endl;
    }
    
    void printMatrix() {
        cout << "Matrix:" << endl;
        cout << "  ";
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
        }
        cout << endl;
        
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    GraphMatrix gm(5);
    
    gm.addEdge(0, 1);
    gm.addEdge(0, 2);
    gm.addEdge(1, 3);
    gm.addEdge(2, 4);
    gm.addEdge(3, 4);
    
    gm.printMatrix();
    gm.DFS(0);
    
    return 0;
}
