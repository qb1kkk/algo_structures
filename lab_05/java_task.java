import java.util.*;

public class TSPGreedy {
    
    public static int tspGreedy(int[][] graph, int start) {
        int n = graph.length;
        boolean[] visited = new boolean[n];
        List<Integer> path = new ArrayList<>();
        
        // Начинаем с начального города
        int current = start;
        visited[current] = true;
        path.add(current);
        
        int totalDistance = 0;
        
        // Посещаем все города
        for (int i = 0; i < n - 1; i++) {
            int nextCity = -1;
            int minDistance = Integer.MAX_VALUE;
            
            // Ищем ближайший непосещенный город
            for (int j = 0; j < n; j++) {
                if (!visited[j] && graph[current][j] < minDistance && graph[current][j] > 0) {
                    minDistance = graph[current][j];
                    nextCity = j;
                }
            }
            
            if (nextCity != -1) {
                totalDistance += minDistance;
                current = nextCity;
                visited[current] = true;
                path.add(current);
            }
        }
        
        // Возвращаемся в начальный город
        totalDistance += graph[current][start];
        path.add(start);
        
        // Выводим путь
        System.out.println("Маршрут: " + path);
        
        return totalDistance;
    }
    
    public static void main(String[] args) {
        // Матрица смежности графа
        int[][] graph = {
            {0, 10, 15, 20},
            {10, 0, 35, 25},
            {15, 35, 0, 30},
            {20, 25, 30, 0}
        };
        
        int startCity = 0;
        int result = tspGreedy(graph, startCity);
        
        System.out.println("Длина пути (жадный алгоритм): " + result);
    }
}
