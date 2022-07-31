#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int u, v, w;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX - 1));
    for (int i = 0; i < n; i++)
    {
        priority_queue<pair<int, int>> pq;
        pq.push({0, i});
        while (!pq.empty())
        {
            int u = pq.top().second;
            int cost = pq.top().first;

            if (dist[i][u] <= cost)
                continue;

            dist[i][u] = cost;

            for (auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;
                pq.push({cost + w, v});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
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