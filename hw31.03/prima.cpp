#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// структура для представления графа в виде списка смежности

struct Graph {
    int V; // количество вершин
    vector<vector<pair<int, int>>> adj; // вектор смежности

    Graph(int V) : V{ V }, adj(V) {} // конструктор

    void add_edge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
};

int d[3] = {};
int vertex=0;

int prim_algorithm(const Graph& graph) {
    int min_cost = 0; // стоимость минимального остовного дерева
    vector<bool> visited(graph.V, false); // массив посещенных вершин
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // очередь с приоритетами {вес_ребра, вершина}
    pq.emplace(0, 0); // начинаем с любой вершины (в данном случае с вершины 0) и веса 0

    while (!pq.empty()) { // пока очередь не пуста
        int u = pq.top().second; // вершина с наименьшим весом
        int w = pq.top().first; // сохраняем вес текущего ребра
        pq.pop();
        if (visited[u]) { // если вершина уже посещена, то перейти к следующей итерации
            continue;
        }
        visited[u] = true; // отметить вершину как посещенную
        min_cost += w; // добавить вес ребра к стоимости минимального остовного дерева
        d[vertex] = u;
        vertex++;
        //cout << u << " "<< endl;
        for (auto& [v, w] : graph.adj[u]) { // проходим по всем соседям вершины
            if (!visited[v]) { // если соседняя вершина не посещена
                pq.emplace(w, v); // добавляем ребро в очередь

            }
        }
    }
    return min_cost;
}

int main() {
    int n = 3; // количество вершин
    Graph graph(n); // создаем граф

    // добавляем ребра графа
    graph.add_edge(0, 1, 1);
    //graph.add_edge(0, 3, 6);
    graph.add_edge(1, 2, 1);
//    graph.add_edge(1, 3, 8);
//    graph.add_edge(1, 4, 5);
//    graph.add_edge(2, 4, 7);
//    graph.add_edge(3, 4, 9);

    
    cout << "Minimum Weight: " << prim_algorithm(graph) << endl;
    for (int i = 0; i < n-1; i++)
    {
        cout<< "(" <<d[i]<< "," << d[i+1]<< ")"<< endl;
    }
    return 0;
}
