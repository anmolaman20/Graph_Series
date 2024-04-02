#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int tsp(int mask, int pos, int n, vector<vector<int>> &cost, vector<vector<int>> &dp)
    {
        int VISITED_ALL = (1 << n) - 1;
        if (mask == VISITED_ALL)
        {
            return cost[pos][0];
        }

        if (dp[mask][pos] != -1)
            return dp[mask][pos];

        int ans = INT_MAX;
        for (int city = 0; city < n; city++)
        {
            if ((mask & (1 << city)) == 0)
            {
                int newAns = cost[pos][city] + tsp(mask | (1 << city), city, n, cost, dp);
                ans = min(ans, newAns);
            }
        }
        return dp[mask][pos] = ans;
    }

public:
    int total_cost(vector<vector<int>> cost)
    {
        int n = cost.size();
        vector<vector<int>> dp((1 << n), vector<int>(n, -1));
        return tsp(1, 0, n, cost, dp);
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        Solution obj;
        int ans = obj.total_cost(cost);
        cout << ans << "\n";
    }
    return 0;
}