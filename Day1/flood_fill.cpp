#include <bits/stdc++.h>
using namespace std;

// Using DFS

class Solution
{
private:
    vector<int> x_dir = {-1, 0, 1, 0};
    vector<int> y_dir = {0, 1, 0, -1};

    void dfs(int cr, int cc, vector<vector<int>> image, vector<vector<int>> &res, int newColor, int initColor)
    {
        res[cr][cc] = newColor;

        for (int k = 0; k < 4; k++)
        {
            int newr = cr + x_dir[k];
            int newc = cc + y_dir[k];

            if (newr >= 0 and newr < image.size() and newc >= 0 and newc < image[0].size() and image[newr][newc] == initColor and res[newr][newc] != newColor)
            {
                dfs(newr, newc, image, res, newColor, initColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int initColor = image[sr][sc];
        vector<vector<int>> res = image;
        dfs(sr, sc, image, res, newColor, initColor);
        return res;
    }
};

// Using BFS

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int initColor = image[sr][sc];
        vector<vector<int>> res = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        res[sr][sc] = newColor;

        vector<int> x_dir = {-1, 0, 1, 0};
        vector<int> y_dir = {0, 1, 0, -1};

        while (!q.empty())
        {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int newr = cr + x_dir[k];
                int newc = cc + y_dir[k];

                if (newr >= 0 and newr < image.size() and newc >= 0 and newc < image[0].size() and image[newr][newc] == initColor and res[newr][newc] != newColor)
                {
                    q.push({newr, newc});
                    res[newr][newc] = newColor;
                }
            }
        }
        return res;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> image[i][j];
            }
        }

        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;

        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}