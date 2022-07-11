/*****************************************************/
/*    Graph : Cycle Detection in Directed Graphs     */
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
        }
        
        bool isCyclic();
        bool isCyclicUtil(int src, vector<bool>& visited, vector<int>& stack);
    
    private:
        // No. of vertices
        int vertices;
        // Pointer to an array containing adjacency lists
        vector<vector<int>> adj;
};


bool Graph::isCyclicUtil(int src, vector<bool>& visited, vector<int>& stack)
{
    stack[src] = true;
    
    if(!visited[src])
    {
        visited[src] = true;
        
        for(auto it : adj[src])
        {
            if(!visited[it] && isCyclicUtil(it, visited, stack))
                return true;
            
            if(stack[it])
                return true;
        }
    }
    
    stack[src] = false;
    
    return false;
}


bool Graph::isCyclic()
{
    int n = adj.size();
    
    vector<bool> visited(n, false);
    vector<int> stack(n, 0);
    bool cyclic = false;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && isCyclicUtil(i, visited, stack))
            cyclic = true;
    }

    if(cyclic)
        return true;
    else
        return false;
}

int main()
{
    Graph g1(5);
    
    g1.addEdge(4, 3);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 1); 
    
    if(g1.isCyclic())
        cout << "Graph has Cycle" << endl;
    else
        cout << "Graph does not has Cycle" << endl;


    Graph g2(5);
    
    g2.addEdge(4, 2); 
    g2.addEdge(0, 1); 
    g2.addEdge(2, 3);
    g2.addEdge(3, 1);
    
    if(g2.isCyclic())
        cout << "Graph has Cycle" << endl;
    else
        cout << "Graph does not has Cycle" << endl;    


    return 0;
}

