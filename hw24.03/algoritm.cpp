#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
using namespace std;


// Алгоритм Беллмана Форда
struct Edges
{
    int u, v, w; // ребра графа выходят из вершины v и входят в вершину u 
                 // w - вес ребра
};

Edges edge[100];
int d[100]; 

/*
d[i] - массив, кратчайшего пути от s до i
*/
void Bellman(int n, int start, int m) // m - количество ребер, n -  количество вершин
{   
    for (int i = 0; i < n+1; i++)
    {
        d[i] = 1000000;
    }
    d[start] = 0;

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (d[edge[j].v] + edge[j].w < d[edge[j].u])
            {
                d[edge[j].u] = d[edge[j].v] + edge[j].w;
            }
        }
    }

    cout << endl << "Путь от вершины " << start << " до ";

    for (int i = 1; i < n + 1; i++)
    {
        cout << endl  << i << " = " << d[i];
    }
}


//Алгоритм Дейкстра
void Deijkstra(int n, int start) // m - количество ребер, n -  количество вершин
{
    bool* visited = new bool[n+1]; //если i = 0->вершина не посещена; i = 1->посещена
    int** GR = new int* [n+1];
    for (int i = 0; i < n+1; i++)
    {
        GR[i] = new int[n+1];
    }

    int s = 0;

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            GR[i][j] = edge[s].w;
            s++;
        }
    }


    for (int i = 1; i < n + 1; i++)
    {
        d[i] = 1000000;
        visited[i] = false;
    }
    d[start] = 0;
    int index = 0, u = 0;

    for (int i = 1; i < n; i++)
    {
        int min = 1000000;
        for (int j = 1; j < n + 1; j++)
        {
            if (!visited[j] && d[j] <= min)
            {
                min = d[j];
                index = j;
            }
        }
        u = index;
        visited[u] = true;
        int maxx = 1000000;

        for (int j = 1; j < n+1; j++)
        {
            if (!visited[j] && GR[u][j] != 1000000 && d[u] != 1000000 && (d[u] + GR[u][j] < d[j]))
            //if (!visited[j] && edge[j].w != maxx && d[edge[j].v] != maxx && (d[edge[j].v] + edge[j].w < d[edge[j].u]))
            {
                //d[j] = d[edge[j].u] + edge[j].u;
                d[j] = d[u] + GR[u][j];
                //d[edge[j].u] = d[edge[j].v] + edge[j].w;
            }
        }
    }


    cout << endl << "Путь от вершины " << start << " до ";

    for (int i = 1; i < n + 1; i++)
    {
        cout << endl << i << " = " << d[i];
    }
}

void originalFloydWarshall(int n) {
    //Пробегаемся по всем вершинам и ищем более короткий путь
    //через вершину k
    int** matrix = new int* [n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        matrix[i] = new int[n + 1];
    }
    
    int s = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            matrix[i][j] = edge[s].w;
            s++;
        }
    }

    //for (int i = 1; i < n + 1; i++) matrix[i][i] = 0;


    for (int k = 1; k < n + 1; k++) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                //Новое значение ребра равно минимальному между старым
                //и суммой ребер i <-> k + k <-> j (если через k пройти быстрее)
                if (matrix[i][k] && matrix[k][j] && i != j)
                {
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j] || matrix[i][j] == 0)
                    {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
                //matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    int* temp = new int[n + 1];

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            temp[j] = matrix[i][j];
        }
        /*for (int k = 1; k< n+1; k++)
            cout << te*/
        for (int k = 1; k < n; k++)
        {
            if (temp[k]!= 0 && temp[k + 1]!=0) d[i] = min(temp[k], temp[k + 1]);
        }
    }
    d[1] = 0;

    cout << endl << "Путь от вершины 1"  << " до ";

    for (int i = 1; i < n + 1; i++)
    {
        cout << endl << i << " = " << d[i];
    }
    


    //
    /*for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++) cout << matrix[i][j] << "\t";
        cout << endl;
    };*/
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите количество вершин:";
    cin >> n;
    int w;
    int m = 1;

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cout << "Введите вес от вершины " << i << " к вершине " << j << "=";
            cin >> w;
            edge[m].v = i; 
            edge[m].u = j;
            edge[m].w = w;
            m++;
        }
    }
    
    int start;
    cout << "Введите начальную вершину: ";
    cin >> start;

    Bellman(n, start , m);

}
