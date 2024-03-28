#include <bits/stdc++.h>
using namespace std;
// Using BFS

class Solution
{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {

        vector<int> x_dir = {-1, 0, 1, 0};
        vector<int> y_dir = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 or j == 0 or i == n - 1 or j == m - 1) and vis[i][j] == 0 and mat[i][j] == 'O')
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nr = cr + x_dir[k];
                int nc = cc + y_dir[k];

                if (nr >= 0 and nr < n and nc >= 0 and nc < m and mat[nr][nc] == 'O' and vis[nr][nc] == 0)
                {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' and vis[i][j] == 0)
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

// Using DFS

class Solution
{
private:
    vector<int> x_dir = {-1, 0, 1, 0};
    vector<int> y_dir = {0, 1, 0, -1};
    void dfs(int cr, int cc, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &mat)
    {
        vis[cr][cc] = 1;

        for (int k = 0; k < 4; k++)
        {
            int nr = cr + x_dir[k];
            int nc = cc + y_dir[k];

            if (nr >= 0 and nr < n and nc >= 0 and nc < m and mat[nr][nc] == 'O' and vis[nr][nc] == 0)
            {
                dfs(nr, nc, n, m, vis, mat);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 or j == 0 or i == n - 1 or j == m - 1) and vis[i][j] == 0 and mat[i][j] == 'O')
                {
                    dfs(i, j, n, m, vis, mat);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' and vis[i][j] == 0)
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
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
        vector<vector<char>> mat(n, vector<char>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution obj;

        vector<vector<char>> ans_mat = obj.fill(n, m, mat);
        for (auto it : ans_mat)
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