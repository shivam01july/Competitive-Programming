/*************************************************************/
/*      Graph - Minimum Spanning Tree (Prim’s Algorithm)     */
/*************************************************************/

#include <bits/stdc++.h>
using namespace std;


class Graph
{
    public:
    
        Graph(int v)
        {
            this->vertices = v;
            edgelist.resize(v);
        }

        void addEdge(int u, int v, int w)
        {
            edgelist[u].push_back({v, w});
            edgelist[v].push_back({u, w});
        }

        
        void mst();
    
    
    private:
        int vertices;
        vector<vector<pair<int, int>>> edgelist;
};


void Graph::mst()
{
    int n = vertices;
    
    vector<int> parent(n);
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    
    int source = 0;
    set<pair<int, int>> set_t;
    // Seting source node to 0
    dist[source] = 0;
    // Format: <dist, parent> / <wt, vertex>
    set_t.insert({0, source});
    int cost = 0;
    
    while(!set_t.empty())
    {
        pair<int, int> x = *set_t.begin();
        set_t.erase(x);
        
        visited[x.second] = true;
        
        int u = x.second; 
        int v = parent[x.second];
        int w = x.first;
        
        cout << u << " -- " << v << " = " << w << endl;
        cost += w; 
        
        for(auto it : edgelist[u])
        {
            if(visited[it.first])
                continue;
            if(dist[it.first] > it.second)
            {
                set_t.erase({dist[it.first], it.first});
                dist[it.first] = it.second;
                set_t.insert({dist[it.first], it.first});  
                parent[it.first] = u;
            }
        }
    } 
    
    cout << "Cost: " << cost << endl;
}


int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    g.addEdge(0, 2, 5);
    g.addEdge(3, 1, 2);
    g.addEdge(3, 2, 40);

    g.mst();
    
    return 0;
}



