#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        vector<int> dist(V, 1e9);
        dist[S] = 0;

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int v = it[0];
                int d = it[1];

                if (dist[node] + d < dist[v])
                {
                    dist[v] = dist[node] + d;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};