#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int tsp_bruteforce(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> vertices;
    
    // Создаем список вершин кроме стартовой
    for (int i = 0; i < n; i++) {
        if (i != start) {
            vertices.push_back(i);
        }
    }
    
    int min_path = INT_MAX;
    
    // Перебираем все перестановки вершин
    do {
        int current_path = 0;
        int k = start;
        
        // Считаем стоимость текущего пути
        for (int i = 0; i < vertices.size(); i++) {
            current_path += graph[k][vertices[i]];
            k = vertices[i];
        }
        current_path += graph[k][start]; // Возвращаемся в начало
        
        min_path = min(min_path, current_path);
        
    } while (next_permutation(vertices.begin(), vertices.end()));
    
    return min_path;
}

int main() {
    // Матрица смежности графа
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    int start_city = 0;
    int result = tsp_bruteforce(graph, start_city);
    
    cout << "Минимальная длина пути: " << result << endl;
    
    return 0;
}
