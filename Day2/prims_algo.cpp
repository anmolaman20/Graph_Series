#include <bits/stdc++.h>
using namespace std;

// Prim's Algorithm
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<bool> vis(V, false);

        int total_cost = 0;

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (vis[u])
                continue;
            vis[u] = true;

            total_cost += wt;

            for (auto &it : adj[u])
            {
                int v = it[0];
                int vwt = it[1];

                pq.push({vwt, v});
            }
        }

        return total_cost;
    }
};
