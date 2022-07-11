/*****************************************************/
/*              Graph : Topological Sort             */
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
        
        vector<int> topologicalSort();
        void findTopoSort(int v, vector<bool>& visited, stack<int>& stack_t);
        
        vector<int> TopoSortKahnsAlgo();
    
    private:
        // No. of vertices
        int vertices;
        // Pointer to an array containing adjacency lists
        vector<vector<int>> adj;
};


void Graph::findTopoSort(int v, vector<bool>& visited, stack<int>& stack_t)
{
    visited[v] = true;
    
    for(auto it : adj[v])
    {
        if(!visited[it])
            findTopoSort(it, visited, stack_t);
    }
    
    stack_t.push(v);
}


vector<int> Graph::topologicalSort()
{
    int n = vertices;
    
    vector<bool> visited(n, false);
    stack<int> stack_t;
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            findTopoSort(i, visited, stack_t);
        }
    }
    
    vector<int> topo;
    
    while(!stack_t.empty())
    {
        topo.push_back(stack_t.top());
        stack_t.pop();
    }
    
    return topo;
}


vector<int> Graph::TopoSortKahnsAlgo()
{
    int n = vertices;
    
    // Create a vector to store indegrees of all vertices. 
    // Initialize all indegrees as 0.
    vector<int> in_deg(n, 0);
    
    // Traverse adjacency lists to fill indegrees of vertices.
    for(int i = 0; i < n; i++)
    {
        for(auto it : adj[i])
            in_deg[it]++;
    }
    
    // Create an queue and enqueue all vertices with indegree 0.
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(!in_deg[i])
            q.push(i);
    }
    
    // Initialize count of visited vertices
	int count = 0;

	// Create a vector to store result (A topological ordering of the vertices)
	vector<int> topo_order;
	
	// One by one dequeue vertices from queue 
	// enqueue adjacents if indegree of adjacent becomes 0
	while(!q.empty())
	{
	    // Extract front of queue and add it to topological order
	    int curr = q.front();
	    q.pop();
	    topo_order.push_back(curr);
	    
	    // Iterate through all neighbouring nodes of dequeued node, and decrease their in-degree by 1
	    for(auto it : adj[curr])
	    {
	        in_deg[it]--;
	        
	        // If in-degree becomes zero, add it to queue
	        if(!in_deg[it])
	            q.push(it);
	    }
	    
	    count++;
	}
    
    // Check if there was a cycle
    if(count != n)
        return { };
    
    return topo_order;  
}


int main()
{
    Graph g(6);
    
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1); 
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> res = g.topologicalSort();
    cout << "Toposort of the Graph : ";
    for(auto it : res)
        cout << it << " ";
    cout << endl;    


    vector<int> res2 = g.TopoSortKahnsAlgo();
    cout << "Toposort of the Khan's Algo : ";
    for(auto it : res2)
        cout << it << " ";
    cout << endl;
    
    return 0;
}


