//Пример 1
import java.util.*;

class Graph {
    private int vertices;
    private List<List<Integer>> adjList;

    public Graph(int v) {
        vertices = v;
        adjList = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        adjList.get(u).add(v);
        adjList.get(v).add(u);
    }

    public void BFS(int start) {
        boolean[] visited = new boolean[vertices];
        Queue<Integer> queue = new LinkedList<>();

        visited[start] = true;
        queue.add(start);

        System.out.print("BFS: ");
        while (!queue.isEmpty()) {
            int current = queue.poll();
            System.out.print(current + " ");

            for (int neighbor : adjList.get(current)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
        System.out.println();
    }

    public void printGraph() {
        for (int i = 0; i < vertices; i++) {
            System.out.print("Vertex " + i + ": ");
            for (int neighbor : adjList.get(i)) {
                System.out.print(neighbor + " ");
            }
            System.out.println();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Graph g = new Graph(5);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 4);
        g.addEdge(3, 4);

        g.printGraph();
        g.BFS(0);
    }
}


//Пример 2
import java.util.*;

class GraphMatrix {
    private int vertices;
    private int[][] adjMatrix;

    public GraphMatrix(int v) {
        vertices = v;
        adjMatrix = new int[vertices][vertices];
    }

    public void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    public void DFS(int start) {
        boolean[] visited = new boolean[vertices];
        Stack<Integer> stack = new Stack<>();

        stack.push(start);

        System.out.print("DFS: ");
        while (!stack.isEmpty()) {
            int current = stack.pop();

            if (!visited[current]) {
                visited[current] = true;
                System.out.print(current + " ");

                for (int i = vertices - 1; i >= 0; i--) {
                    if (adjMatrix[current][i] == 1 && !visited[i]) {
                        stack.push(i);
                    }
                }
            }
        }
        System.out.println();
    }

    public void printMatrix() {
        System.out.println("Matrix:");
        System.out.print("  ");
        for (int i = 0; i < vertices; i++) {
            System.out.print(i + " ");
        }
        System.out.println();

        for (int i = 0; i < vertices; i++) {
            System.out.print(i + " ");
            for (int j = 0; j < vertices; j++) {
                System.out.print(adjMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        GraphMatrix gm = new GraphMatrix(5);

        gm.addEdge(0, 1);
        gm.addEdge(0, 2);
        gm.addEdge(1, 3);
        gm.addEdge(2, 4);
        gm.addEdge(3, 4);

        gm.printMatrix();
        gm.DFS(0);
    }
}
