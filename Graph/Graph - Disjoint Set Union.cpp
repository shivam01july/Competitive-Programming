/*****************************************************/
/*          Graph - Disjoint Set Union (DSU)         */
/*****************************************************/

#include <bits/stdc++.h>
using namespace std;


class Graph
{
    public:
    
        // Constructor
        Graph(int v)
        {
            this->vertices = v;
            adj.resize(v);
            
            parent.resize(v);
            size.resize(v);
        }

        // Function to add an edge to graph
        void addEdge(int v, int w)
        {
            adj[v].push_back(w);
            adj[w].push_back(v);
        }
        
        
        bool isCyclic();
        
        void make_set(int v);
        int find_set(int v);
        void union_sets(int a, int b);
        
    
    private:
        // No. of vertices
        int vertices;
        // Pointer to an array containing adjacency lists
        vector<vector<int>> adj;
        
        vector<int> parent;
        vector<int> size;
};


void Graph::make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}


int Graph::find_set(int v)
{
    if(v == parent[v])
        return v;
    
    return parent[v] = find_set(parent[v]);
}


void Graph::union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    
    if(a != b)
    {
        if(size[a] < size[b])
            swap(a, b);
            
        parent[b] = a;
        size[a] += size[b];
    }
}


bool Graph::isCyclic()
{
    for(int i = 0; i < vertices; i++)
        make_set(i);
       
    bool cycle = false;
    for(int i = 0; i < vertices; i++)
    {
        int u = adj[i][0];
        int v = adj[i][1];
        
        int x = find_set(u);
        int y = find_set(v);
        
        if(x == y)
            cycle = true;
        else
            union_sets(u, v);
    }
    
    return cycle;
}


int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(4, 2);
    
    
    if(g.isCyclic())
        cout << "Graph has Cycle" << endl;
    else
        cout << "Graph does not has Cycle" << endl;


    return 0;
}


