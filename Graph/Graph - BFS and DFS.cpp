/******************************************/
/*          Graph : BFS and DFS           */
/******************************************/

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
        
        void printBFS(int v); 
        
        void printDFS(int v);
    
    private:
        // No. of vertices
        int vertices;
        // Pointer to an array containing adjacency lists
        vector<list<int>> adj;
};


void Graph::printBFS(int v)
{
    // Create a queue of size vertices and mark all as not visited
    vector<bool> visited;
    visited.resize(vertices, false);
    
    // Create a queue for BFS
    queue<int> queue_t;
    
    // Mark the current node as visited and enqueue it
    visited[v] = true;
    queue_t.push(v);
    
    
    while(!queue_t.empty())
    {
        // Dequeue a vertex from queue and print it
        v = queue_t.front();
        cout << v << " ";
        queue_t.pop();
        
        // Get all adjacent vertices of the dequeued vertex s. 
        // If a adjacent has not been visited, then mark it visited and enqueue it
        for(auto it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                queue_t.push(*it);
            }
        }
    }
}


void Graph::printDFS(int v)
{
    static vector<bool> visited;
    visited.resize(vertices, false);
    
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
    
    // Recur for all the vertices adjacent to this vertex
    for(auto it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if(!visited[*it])
        {
            printDFS(*it);
        }
    }
}


int main()
{
    Graph g(4);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    int v = 2;
    
    cout << "BFS starting from vertex " << v << ": ";
    g.printBFS(v);
    cout << endl;
    
    cout << "DFS starting from vertex " << v << ": ";
    g.printDFS(v);
    cout << endl;
}



