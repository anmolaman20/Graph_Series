#include <bits/stdc++.h>
using namespace std;

// Using BFS

class Solution
{
private:
    bool detectCycle(int src, vector<int> adj[], vector<int> &vis)
    {
        queue<pair<int, int>> q;
        vis[src] = 1;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (parent != it)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectCycle(i, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// Using DFS

class Solution
{
private:
    bool dfs(int src, int parent, vector<int> adj[], vector<int> &vis)
    {
        vis[src] = 1;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                if (dfs(it, src, adj, vis) == true)
                    return true;
            }
            else if (parent != it)
            {
                return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        cout << obj.isCycle(V, adj) << endl;
    }
    return 0;
}