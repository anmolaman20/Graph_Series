#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int curr, vector<bool> &vis, vector<int> adj[])
    {
        vis[curr] = true;
        for (auto it : adj[curr])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj);
            }
        }
    }
    bool Connected_Graph(int V, vector<int> adj[])
    {
        vector<bool> vis(V + 1, false);
        int node = -1;
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() > 0)
            {
                node = i;
                break;
            }
        }
        if (node == -1)
        {
            return true;
        }

        dfs(node, vis, adj);

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false and adj[i].size() > 0)
            {
                return false;
            }
        }

        return true;
    }
    int find_Euler(int V, vector<int> adj[])
    {
        if (!Connected_Graph(V, adj))
        {
            return 0;
        }

        int odd = 0;

        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() & 1)
            {
                odd++;
            }
        }

        if (odd > 2)
            return 0;

        return (odd == 0) ? 2 : 1;
    }

public:
    int isEulerCircuit(int V, vector<int> adj[])
    {
        return find_Euler(V, adj);
    }
};