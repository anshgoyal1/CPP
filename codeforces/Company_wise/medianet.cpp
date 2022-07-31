#include <bits/stdc++.h>
using namespace std;
#define int long long

void sol(int n, vector<int> &cost, int c_size, vector<vector<int>> &c, int taxFactor)
{
    vector<pair<int, int>> adj[n];

    for (int i = 0; i < c_size; i++)
    {
        int u = c[i][0] - 1;
        int v = c[i][1] - 1;
        int t = c[i][2];

        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    vector<int> minCost(n);
    vector<int> vis(n, 0);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        minCost[i] = cost[i];
        q.push({minCost[i], i});
    }

    while (!q.empty())
    {
        int u = q.front().second;
        int cos = q.front().first;
        q.pop();

        if (vis[u])
        {
            continue;
        }

        vis[u] = 1;

        for (auto [v, tax] : adj[u])
        {
            int newCost = cost[u] + tax * (1 + taxFactor);

            if (newCost < minCost[v])
            {
                minCost[v] = newCost;
                q.push({newCost, v});
            }
        }
    }

    for (auto it : minCost)
    {
        cout << it << " ";
    }
}

void solve()
{
    int a;
    cin >> a;
    vector<int> cost;
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        cost.push_back(x);
    }

    int c_size;
    cin >> c_size;
    vector<vector<int>> c(c_size, vector<int>(3));
    for (int i = 0; i < c_size; i++)
    {
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    }

    int d;
    cin >> d;

    sol(a, cost, c_size, c, d);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)

        solve();

    return 0;
}