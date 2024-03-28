#include <bits/stdc++.h>
using namespace std;

// Using DFS

class Solution
{
private:
    vector<int> x_dir = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> y_dir = {0, 1, 1, 1, 0, -1, -1, -1};

    void dfs(int i, int j, vector<vector<char>> grid, vector<vector<int>> &vis)
    {
        vis[i][j] = 1;

        for (int k = 0; k < 8; k++)
        {
            int new_row = i + x_dir[k];
            int new_col = j + y_dir[k];

            if (new_row >= 0 and new_row < grid.size() and new_col >= 0 and new_col < grid[0].size() and grid[new_row][new_col] == '1' and vis[new_row][new_col] == 0)
            {
                dfs(new_row, new_col, grid, vis);
            }
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int cnt_isd = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' and vis[i][j] == 0)
                {
                    cnt_isd++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt_isd;
    }
};

// Using BFS

class Solution
{
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        vector<int> x_dir = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> y_dir = {0, 1, 1, 1, 0, -1, -1, -1};
        int cnt_isd = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' and vis[i][j] == 0)
                {
                    cnt_isd++;
                    vis[i][j] = 1;

                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty())
                    {
                        int curr_row = q.front().first;
                        int curr_col = q.front().second;
                        q.pop();
                        for (int k = 0; k < 8; k++)
                        {
                            int new_row = curr_row + x_dir[k];
                            int new_col = curr_col + y_dir[k];

                            if (new_row >= 0 and new_row < grid.size() and new_col >= 0 and new_col < grid[0].size() and grid[new_row][new_col] == '1' and vis[new_row][new_col] == 0)
                            {
                                vis[new_row][new_col] = 1;
                                q.push({new_row, new_col});
                            }
                        }
                    }
                }
            }
        }
        return cnt_isd;
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

        vector<vector<char>> grid(n, vector<char>(m, '#'));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.numIslands(grid) << endl;
    }

    return 0;
}