#include <bits/stdc++.h>
using namespace std;

/* Method 2 -> Using DFS */

class Solution
{
private:
    void dfs(int i, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
                dfs(it, vis, st, adj);
        }
        st.push(i);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, vis, st, adj);
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
