/*************************************************************/
/*       Graph - Shortest Path (Dijkstra’s Algorithm)        */
/*************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define V 9

class Graph
{
    public:
    
        Graph(int v)
        {
            this->vertices = v;
            graph.resize(v);
        }

        void addEdge(int u, int v, int w)
        {
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        
        void shortestPath(int source);
    
    
    private:
        int vertices;
        vector<vector<pair<int, int>>> graph;
};


void Graph::shortestPath(int source)
{
    int n = vertices;

    vector<int> dist(n, INT_MAX);  // {vertex, wt}
    set<pair<int, int>> set_t;     // {wt, vertex}
    dist[source] = 0;
    set_t.insert({0, source});
    
    while(!set_t.empty())
    {
        pair<int, int> x = *set_t.begin();
        set_t.erase(x);
        
        for(auto it : graph[x.second])
        {
            if(dist[it.first] > dist[x.second] + it.second)
            {
                set_t.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                set_t.insert({dist[it.first], it.first});
            }
        }
    }
    
    
    cout << "Vertex \t Dist form Source" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "   " << i << "\t\t"; 
        if(dist[i] == INT_MAX)
            cout << "-1" << " ";
        else
            cout << dist[i] << " ";
        cout << endl;    
    }
}


int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int source = 0;

    g.shortestPath(source);
    
    
    return 0;
}




