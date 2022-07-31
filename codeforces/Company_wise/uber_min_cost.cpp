#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node
{
    int x;
    int y;
    int z;
};

int dist(Node *a, Node *b)
{
    int ans = 0;
    ans += abs(a.x - b.x);
    ans += abs(a.y - b.y);
    ans += abs(a.z - b.z);

    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<Node *> v(n);

    int x, y, z;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y >> v[i].z;
    }
    vector<pair<int, Node *>> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            int cost = dist(v[i], v[j]);
            adj[i].push_back({cost, j});
            adj[j].push_back({cost, i});
        }
    }

    int parent[n];
    int key[n];
    int mstSet[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mstSet[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (adj[i][parent[i]]);
    }

    cout << ans << endl;
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