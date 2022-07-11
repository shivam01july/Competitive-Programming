/*************************************************************/
/*    Graph - Minimum Spanning Tree (Kruskal’s Algorithm)    */
/*************************************************************/

#include <bits/stdc++.h>
using namespace std;


class Graph
{
    public:
    
        Graph(int v)
        {
            this->vertices = v;
        }

        void addEdge(int u, int v, int w)
        {
            edgelist.push_back({w, u, v});
        }
        
        void init(int n)
        {
            parent.resize(n);
            size.resize(n);
        }
        
        
        void mst();
        
        void make_set(int v);
        int find_set(int v);
        void union_sets(int a, int b);
    
    private:
        int vertices;
        vector<vector<int>> edgelist;
        
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
    
    if(size[a] < size[b])
        swap(a, b);
        
    parent[b] = a;
    size[a] += size[b];
}


void Graph::mst()
{
    int n = edgelist.size();
    init(n);
    
    for(int i = 0; i < n; i++)
        make_set(i);
    
    sort(edgelist.begin(), edgelist.end());
     
    int cost = 0;    
    for(int i = 0; i < n; i++)
    {
        int w = edgelist[i][0];
        int u = edgelist[i][1];
        int v = edgelist[i][2];
        
        int x = find_set(u);
        int y = find_set(v);
        
        if(x == y)
            continue;
        else
        {
            cout << u << " -- " << v << " = " << w << endl;
            cost += w;
            union_sets(u, v);
        }
    }
    
    cout << "Cost: " << cost << endl;
    
    
}


int main()
{
    Graph g(6);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(1, 4, 10);
    g.addEdge(1, 5, 5);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 5, 2);

    g.mst();
    
    return 0;
}


