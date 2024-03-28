#include <bits/stdc++.h>
using namespace std;

// using Adjaceny List -> uses O(2*E)  ->(2E -> Degree)

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adjList[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

// using AdjacencyList -> uses O(V*V) space

int main()
{
    int V, E;
    cin >> V >> E;
    int adjMat[V][V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
}
