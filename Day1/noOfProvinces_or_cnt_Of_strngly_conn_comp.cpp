// problem Link ->>  https://www.geeksforgeeks.org/problems/number-of-provinces/1?ref=gcse

#include <bits/stdc++.h>
using namespace std;

// BFS

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<int> adjList[V];
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[0].size(); j++)
            {
                if (adj[i][j] == 1 and i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int noOfprovinces = 0;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                noOfprovinces++;
                vis[i] = 1;
                queue<int> q;
                q.push(i);
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for (auto it : adjList[node])
                    {
                        if (!vis[it])
                        {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        return noOfprovinces;
    }
};

// DFS

/*

class Solution {
  private:
    void dfs(int node,vector<int>& vis, vector<int> adj[]){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjList[V];
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j]==1 and i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }


        int noOfprovinces = 0;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                noOfprovinces++;
                dfs(i,vis,adjList);
            }
        }
        return noOfprovinces;
    }
};

*/

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.numProvinces(adj, V) << endl;
    }
    return 0;
}