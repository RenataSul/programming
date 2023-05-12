#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 1000; // максимальное количество вершин

vector<int> g[MAXN]; // список смежности
int n, m; // количество вершин в первой и второй долях соответственно
int match[MAXN]; // массив паросочетания
bool used[MAXN]; // массив посещенных вершин

bool kuhn(int v) {
    if (used[v])
        return false;

    used[v] = true;

    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (match[to] == -1 || kuhn(match[to])) {
            match[to] = v;
            return true;
        }
    }

    return false;
}

int max_matching() {
    memset(match, -1, sizeof(match));
    int max_match = 0;

    for (int i = 0; i < n; i++) {
        memset(used, false, sizeof(used));
        if (kuhn(i))
            max_match++;
    }

    return max_match;
}

int main()
{
    /*
    n = 3;
    m = 4;
    
    g[0].push_back(0); // ребро из первой вершины в первую
    g[0].push_back(1); // ребро из первой вершины во вторую
    g[1].push_back(2); // ребро из второй вершины в третью
    g[2].push_back(1); // ребро из третьей вершины во вторую
    g[2].push_back(3); // ребро из третьей вершины в четвертую
    */
    n = 4;
    m = 4;
    g[0].push_back(1); 
    g[0].push_back(2); 
    g[1].push_back(1); 
    g[2].push_back(0); 
    g[2].push_back(3); 
    g[3].push_back(1);
    g[3].push_back(3);
    cout << max_matching();
}

