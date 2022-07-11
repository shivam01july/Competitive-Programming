/*****************************************************/
/*    Graph : Cycle Detection in Undirected Graphs   */
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
        }

        // Function to add an edge to graph
        void addEdge(int v, int w)
        {
            adj[v].push_back(w);
            adj[w].push_back(v);
        }
        
        bool isCyclic();
        bool isCyclicUtil(int src, vector<bool>& visited, int parent);
    
    private:
        // No. of vertices
        int vertices;
        // Pointer to an array containing adjacency lists
        vector<vector<int>> adj;
};


bool Graph::isCyclicUtil(int src, vector<bool>& visited, int parent)
{
    visited[src] = true;
    
    for(auto it : adj[src])
    {
        if(it != parent)
        {
            if(visited[it])
                return true;
            
            if(!visited[it] && isCyclicUtil(it, visited, src))
                return true;
        }
    }
    
    return false;
}


bool Graph::isCyclic()
{
    int n = adj.size();
    
    vector<bool> visited(n, false);
    bool cycle = false;
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && isCyclicUtil(i, visited, -1))
            cycle = true; 
    }
    
    if(cycle)
        return true;
    else
        return false;
}

int main()
{
    Graph g(5);
    
    g.addEdge(4, 3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    
    if(g.isCyclic())
        cout << "Graph has Cycle" << endl;
    else
        cout << "Graph does not has Cycle" << endl;


    g.addEdge(2, 0);
    
    if(g.isCyclic())
        cout << "Graph has Cycle" << endl;
    else
        cout << "Graph does not has Cycle" << endl;    


    return 0;
}
