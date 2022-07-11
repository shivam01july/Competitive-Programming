/*********************************************************/
/*      Graph : Matrix and List Representation           */
/*********************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define V 4


void InsertEdge(int arr[][V], int i, int j)
{
    arr[i][j] = 1;
    arr[j][i] = 1;
}


void PrintAdjMatrix(int arr[][V])
{
    for(int i = 0; i < V; i++)
    {
        cout << "Adjacency Matrix Vertex: " << i << " : ";
        for(int j = 0; j < V; j++)
        {
            cout << arr[i][j] << " ";   
        }
        cout << endl;
    }
    cout << endl;
}


void AddEdge(vector<int> vec[], int i, int j)
{
   vec[i].push_back(j);
   vec[j].push_back(i);
}


void PrintAdjList(vector<int> v[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "Adjacency List Vertex: " << i; 
        for (auto it = v[i].begin(); it != v[i].end(); it++)
        {
            cout << " -> " << *it;
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    /* Adjacency Matrix */
    int adjMatrix[V][V];
    
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            adjMatrix[i][j] = 0;
            
    InsertEdge(adjMatrix, 0, 1);  
    InsertEdge(adjMatrix, 0, 2);  
    InsertEdge(adjMatrix, 1, 2);  
    InsertEdge(adjMatrix, 2, 0);  
    InsertEdge(adjMatrix, 2, 3);  

    PrintAdjMatrix(adjMatrix);


    /* Adjacency List */
    vector<int> adjList[V];
    
    AddEdge(adjList, 0, 1);
    AddEdge(adjList, 1, 2);
    AddEdge(adjList, 1, 3);
    AddEdge(adjList, 2, 3);
    AddEdge(adjList, 3, 0);
    
    PrintAdjList(adjList, V);


    return 0;
}

