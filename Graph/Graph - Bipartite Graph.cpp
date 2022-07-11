/*****************************************************/
/*              Graph - Bipartite Graph              */
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
        
        bool isBipartite();
        bool checkBipartite(int v, int curr, vector<int>& color);
    
    private:
        // No. of vertices
        int vertices;
        // Pointer to an array containing adjacency lists
        vector<vector<int>> adj;
        
        vector<int> parent;
        vector<int> size;
};


bool Graph::checkBipartite(int v, int curr, vector<int>& color)
{
    if(color[v] != -1)
    {
        if(color[v] != curr)
            return false;
        else
            return true;
    }    
        
    color[v] = curr;
    
    for(auto it : adj[v])
    {
        if(!checkBipartite(it, !curr, color))
            return false;
    }
    return true;
}


bool Graph::isBipartite()
{
    int n = adj.size();
    vector<int> color(n, -1);
    
    for(int i = 0; i < n; i++)
    {
        if(color[i] == -1)
        {
            if(!checkBipartite(i, 0, color))
                return false;
        }
    }           
    
    return true;
}


int main()
{
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    
    if(g1.isBipartite())
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is not Bipartite" << endl;
    
    
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0);
    
    if(g2.isBipartite())
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is not Bipartite" << endl;

    return 0;
}



