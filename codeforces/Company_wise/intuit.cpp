#include <bits/stdc++.h>
using namespace std;
#define int long long

int minKey(vector<int> &key, vector<bool> &mstSet, int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<vector<int>> dist(n + 2, vector<int>(n + 2));
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            cout << dist[i][j] << " ";
        }

        cout << endl;
    }

    vector<int> parent(n + 2);
    vector<bool> mstSet(n + 2, false);
    vector<int> key(n + 2, INT_MAX);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n; count++)
    {
        int u = minKey(key, mstSet, n + 2);

        mstSet[u] = true;

        for (int v = 0; v <= n + 1; v++)
        {
            if (mstSet[v] = false and dist[u][v] > 0 and dist[u][v] < key[v])
            {
                parent[v] = u;
                key[u] = dist[u][v];
            }
        }
    }
    int cost = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        cout << parent[i] << " - " << i << " \t" << dist[i][parent[i]] << " \n";
        cost += dist[i][parent[i]];
    }
    cout << cost << endl;
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