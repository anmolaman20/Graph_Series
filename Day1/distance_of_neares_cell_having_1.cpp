#include <bits/stdc++.h>
using namespace std;

// BFS

class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<int> x_dir = {-1, 0, 1, 0};
        vector<int> y_dir = {0, 1, 0, -1};

        while (!q.empty())
        {
            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int cd = q.front().second;
            q.pop();

            dist[cr][cc] = cd;

            for (int k = 0; k < 4; k++)
            {
                int nr = cr + x_dir[k];
                int nc = cc + y_dir[k];

                if (nr >= 0 and nr < n and nc >= 0 and nc < m and vis[nr][nc] == 0 and grid[nr][nc] == 0)
                {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, cd + 1});
                }
            }
        }
        return dist;
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
        vector<vector<int>> ans = obj.nearest(grid);

        for (auto it : ans)
        {
            for (auto jt : it)
            {
                cout << jt << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}