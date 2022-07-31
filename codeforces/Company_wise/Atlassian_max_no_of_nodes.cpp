#include <bits/stdc++.h>
using namespace std;
#define int long long

int dijkstra(vector<pair<int, int>> adj[], int src, int thres, int n)
{
    vector<bool> vis(n + 1, false);
    vector<int> dist(n + 1, INT_MAX);
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater < int, int >>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int w = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if (vis[u])
        {
            continue;
        }

        vis[u] = true;

        for (auto x : adj[u])
        {
            int v = x.first;
            int w = x.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i != src && dist[i] <= thres)
        {
            c++;
        }
    }

    return c;
}

void solve()
{
    int distanceThres;
    cin >> distanceThres;
    int n;
    cin >> n;

    vector<int> city_from = {1, 2};
    vector<int> city_to = {2, 3};
    vector<int> city_weight = {3, 1};

    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < 2; i++)
    {
        adj[city_from[i]].push_back({city_to[i], city_weight[i]});
        adj[city_to[i]].push_back({city_from[i], city_weight[i]});
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back({dijkstra(adj, i, distanceThres, n), i});
    }

    sort(ans.begin(), ans.end());
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