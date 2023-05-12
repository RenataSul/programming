#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>

// рассчитать максимальный поток, разобраться с f,  найти ребра среза

using namespace std;

typedef pair<int, int> PII; // PII для хранение (вершина, расстояние)

const int INF = numeric_limits<int>::max(); // бесконечность
static int CntOfFlow = 0;
int cnt_f= 0;
struct Graph {
    int V; // количество вершин
    int *check_vert = new int[V];
    vector <int> vertices;
    vector<vector<PII>> adj; // вектор списков смежности
    vector<vector<PII>> adj2;
    map <pair<int, int>, int> f;
    vector <int> pathr;
    Graph(int V) : V(V), adj(V) {}
    pair <int, int> p, p1;
    // добавление ребра в граф (направленный граф)
    void addEdge(int u, int v) {
        if (u == 0)
        {
            cnt_f++;
        }
        adj[u].push_back(make_pair(v, 1));
        adj[v].push_back(make_pair(u, 1));

        p = make_pair(u,v);
        f[p] = 0;
        p = make_pair(v, u);
        f[p] = 0;

    }

    void adj_2()
    {
        adj2 = adj;
    }

    void removeEdge(int u, int v) {
    // перебираем смежные вершины у, чтобы найти v

    cout << endl<<"U= "<<u;
    cout << " V=" << v;
    for (auto it = adj[u].begin(); it != adj[u].end(); it++) {

            if ( (it -> first) == v)
            {
                //cout << "\ni->f: "<<it -> first<< endl;
                cout <<"\nu: "<< u;
                cout <<"\nfirst: "<< it -> first << " second: "<< it -> second;

                adj[u].erase(it); //неуверена что следует убрать, но пока работает

                p = make_pair(u, v);
                f[p] ++;
                cout << endl<<"f["<< u<<","<<  v<< "] = "<< f[p];
                break;
            }
        }
    cout <<endl<<"END REMOVE"<< endl;
    }

    // алгоритм Дейкстры
    int dijkstra(int s)
    {
        // расстояния до вершин
        vector<int> dist(V, INF);
        // очередь с приоритетом для обработки вершин
        priority_queue<PII, vector<PII>, greater<>> pq;
        // массив для хранения предыдущих вершин на кратчайшем пути
        vector<int> prev(V, -1);


        // расстояние до начальной вершины равно 0
        dist[s] = 0;
        pq.push(make_pair(0, s));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // для каждого соседа v вершины u
            for (const auto& [v, w] : adj[u])
                {
                    //cout << u <<" "<< v<<endl
                    // если новый путь короче старого
                    pair <int, int> p = make_pair(u, v);
                    if (dist[u] != INF && (dist[v] > dist[u] + w) && f[p] == 0 ) {
                        // обновляем расстояние до v
                        dist[v] = dist[u] + w;
                        prev[v] = u;
                        pq.push(make_pair(dist[v], v));
                    }
                }

        }

        // выводим расстояния до всех вершин
        /*
        for (int v = 1; v < V; ++v) {
            cout <<endl <<"Vertex " << v << ": " << dist[v] ;
        }
        */

        // восстанавливаем путь
        vector<int> path;

        for (int u = V-1; u != -1; u = prev[u]) {
            path.push_back(u);
        }
        if (path.size()<= 1) return 0;

        cout << endl << endl<<"PATH: ";
        //реверс path в pathr
        for (int i = path.size() - 1; i >= 0; --i) {
            //cout << path[i] << " ";
            pathr.push_back(path[i]);
        }


        for (int i = 0; i < pathr.size() ; ++i)
        {
            cout << pathr[i] << " ";
        }

        cout << endl;

        //все функции равны нулю изначально
        for (int i = 0; i < pathr.size()-1; i++)
        {
            p = make_pair(pathr[i], pathr[i+1]);
            f[p] = 0;
            //cout <<"key: " <<f -> first << "val: "<< f->second;

        }

        // Удаляем ребра смежности
        cout << "\n----------REMOVE EDGE-----------";
        for (int i =0; i < pathr.size()-1; i++)
        {
            removeEdge(pathr[i], pathr[i+1]);
        }



    CntOfFlow ++;
    path.clear();
    pathr.clear();
    cnt_f--;
    if (cnt_f > 0)
    {
        dijkstra(0);
    }


    }

    void print_graph()
    {
        int u = 0;
        while (u< V -1)
        {
            for (const auto& [v, w] : adj[u])
            {
                cout << u<< ", " << v<< endl;
            }
            u ++;
        }
    }

    void delete_edje()
    {
        int u = 0;
        while (u< V -1)
        {
            for (const auto& [v, w] : adj[u])
            {
                p = make_pair(u, v);
                p1= make_pair(v, u);

                if (f[p] != f[p1])
                {
                    if (f[p] == 0) removeEdge(u, v);
                    else removeEdge(v, u);
                }

                //cout << u<< ", " << v<< endl;
            }
            u ++;
        }
    }

    void check_v()
    {

        //сделать обход в ширину!!!!! и не заплакать
        //все что ниже неправильно если что почитать переписку с Сережей
        /*
        priority_queue<PII, vector<PII>, greater<>> pq2;
        vector<int> dist(V, INF);
        pq2.push(make_pair(0, 0));
        dist[0] = 0;
        while (!pq2.empty()) {
            int u = pq2.top().second;
            pq2.pop();

            for (const auto& [v, w] : adj[u])
            {
                if (dist[u] != INF && (dist[v] > dist[u] + w) && f[p] == 0 ) {
                        // обновляем расстояние до v
                        dist[v] = dist[u] + w;
                        pq2.push(make_pair(dist[v], v));
                    }
                cout <<endl<< u << ", "<< v;
                check_vert[v] = 1;
            }
        }
        */
        //помечаем пройденные вершины
        //p = make_pair(7, 4);
        //cout << f[p];
        int u = 0;
        int temp_val = 0;
        while (u< V)
        {
            for (const auto& [v, w] : adj[u])
            {
                /*
                p = make_pair(u, v);
                //p1 = make_pair(v, u);
                if (f[p] == 1 && u != 0 )
                {
                    check_vert[u] = 1;
                    cout << u<< ", " << v<< endl;
                    //u = v;
                }
                */
                //cout << u<< ", " << v<< endl;
                p = make_pair(u, v);
                p1 = make_pair(v, u);
                if (f[p] == 0 && f[p1] == 0 )//&& v!= temp_val)
                {
                    check_vert[u] = 1;
                    cout <<"PAIR:" <<u<< ", " << v<< endl;
                    //temp_val = u;
                    //u = v;


                }


            }
            u++;
        }
        check_vert[0] = 0;
        cout << "CHECK VERT"<< endl;
            for (int i = 0; i < V; i++ )
            {
                cout << check_vert[i] << ", ";

            }
            cout << endl;


        u = 1;
        while (u< V -1)
        {
            for (const auto& [v, w] : adj2[u])
            {
                p = make_pair(u, v);
                //p1 = make_pair(v, u);
                p1 = make_pair(u, v);
                if (check_vert[u] && !check_vert[v] && u < v)//&& v != 0 && f[p] ==0 && f[p1] == 0)
                {
                    cout << "("<< u<< ", "<< v<<")"<< endl;

                }

            }
            u++;
        }
        /*
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                p = make_pair(i, j);

                if ((check_vert[i] != check_vert[j] ) && f.count(p)) cout <<"(" << i << "," << j << ")";
            }

        }
        */

    }

};



int main() {
    //при проверке на новом графе важно изменить V - количество вершин
    // также необходимо искать путь от 0 до наибольшей вершины
    // ну не могу по-другому сделать((

    setlocale(0, "rus");
    const int V = 10;
    Graph graph(V);

    // добавляем ребра
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 9);
    graph.addEdge(4, 2);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.addEdge(6, 8);
    graph.addEdge(0, 7);
    graph.addEdge(7, 4);
    graph.addEdge(6, 9);
    graph.addEdge(8, 9);

    graph.adj_2();

    cout<<"cnt_f_0 = " <<cnt_f<< endl;

    cout << "kdjcsmk"<<endl;
    graph.print_graph();
    graph.dijkstra(0);
    //graph.delete_edje();

    cout << '\n';

    cout << endl<<endl<<"MAX FLOW: " ;
    cout << CntOfFlow<< endl;
    graph.check_v();
    /*
    теперь мин срез
    нужно найти минимальный срез, который = макс потоку
    нужно вывести ребра, через которые будет проходить этот срез

     */

    return 0;
}
