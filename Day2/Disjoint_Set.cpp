#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
