#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];

        queue<pair<pair<int, int>, int>> q;
        int freshOrg = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }

                if (grid[i][j] == 1)
                    freshOrg++;
            }
        }

        int Time = 0;
        vector<int> x_dir = {-1, 0, 1, 0};
        vector<int> y_dir = {0, 1, 0, -1};

        while (!q.empty())
        {

            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int t = q.front().second;
            q.pop();

            Time = max(Time, t);

            for (int k = 0; k < 4; k++)
            {
                int nr = cr + x_dir[k];
                int nc = cc + y_dir[k];

                if (nr >= 0 and nr < grid.size() and nc >= 0 and nc < grid[0].size() and vis[nr][nc] == 0 and grid[nr][nc] == 1)
                {
                    vis[nr][nc] = 2;
                    freshOrg--;
                    q.push({{nr, nc}, t + 1});
                }
            }
        }
        if (freshOrg != 0)
            return -1;
        return Time;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.orangesRotting(grid) << endl;
    }
    return 0;
}