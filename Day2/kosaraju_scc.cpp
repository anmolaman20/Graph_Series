#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &Stack)
    {
        visited[v] = true;
        for (int u : adj[v])
        {
            if (!visited[u])
                dfs(u, adj, visited, Stack);
        }
        Stack.push(v);
    }

    void dfsReverse(int v, vector<vector<int>> &adjReverse, vector<bool> &visited)
    {
        visited[v] = true;
        for (int u : adjReverse[v])
        {
            if (!visited[u])
                dfsReverse(u, adjReverse, visited);
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // Step 1: First DFS pass to fill the stack
        stack<int> Stack;
        vector<bool> visited(V, false);
        for (int v = 0; v < V; ++v)
        {
            if (!visited[v])
                dfs(v, adj, visited, Stack);
        }

        // Step 2: Reverse the graph
        vector<vector<int>> adjReverse(V);
        for (int v = 0; v < V; ++v)
        {
            for (int u : adj[v])
            {
                adjReverse[u].push_back(v);
            }
        }

        // Step 3: Second DFS pass to count SCCs
        visited.assign(V, false);
        int SCC_count = 0;
        while (!Stack.empty())
        {
            int v = Stack.top();
            Stack.pop();
            if (!visited[v])
            {
                dfsReverse(v, adjReverse, visited);
                SCC_count++;
            }
        }

        return SCC_count;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
