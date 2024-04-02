#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &disc, vector<int> &low, stack<int> &st, vector<bool> &isInStack, vector<vector<int>> &ans, vector<int> adj[], int &tm)
    {

        disc[node] = low[node] = tm;
        tm += 1;
        st.push(node);
        isInStack[node] = true;

        for (int v : adj[node])
        {
            if (disc[v] == -1)
            {
                dfs(v, disc, low, st, isInStack, ans, adj, tm);
                low[node] = min(low[node], low[v]);
            }
            else if (isInStack[v])
            { // back edge
                low[node] = min(low[node], disc[v]);
            }
        }

        if (disc[node] == low[node])
        {
            vector<int> res;
            while (!st.empty() && st.top() != node)
            {
                res.push_back(st.top());
                isInStack[st.top()] = false;
                st.pop();
            }
            if (!st.empty())
            {
                res.push_back(st.top());
                isInStack[st.top()] = false;
                st.pop();
            }

            sort(res.begin(), res.end());
            ans.push_back(res);
        }
    }

public:
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<vector<int>> ans;
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> isInStack(V, false);
        stack<int> mystack;
        int tm = 0;

        for (int i = 0; i < V; i++)
        {
            if (disc[i] == -1)
            {
                dfs(i, disc, low, mystack, isInStack, ans, adj, tm);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
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

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                if (j == ptr[i].size() - 1)
                    cout << ptr[i][j];
                else
                    cout << ptr[i][j] << " ";
            }
            cout << ',';
        }
        cout << endl;
    }

    return 0;
}
