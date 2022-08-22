#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;

vector<int> parent;
vector<int> sz;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }

    return parent[u] = find(parent[u]);
}

void unionn(int u, int v)
{
    int a = find(u);
    int b = find(v);

    if (a == b)
    {
        return;
    }

    if (sz[a] > sz[b])
    {
        sz[a] += sz[b];
        parent[b] = a;
    }
    else
    {
        sz[b] += sz[a];
        parent[a] = b;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }

    sort(a.begin(), a.end(), comp);
    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        // sz[i] = 1;
    }
    int c = 0;
    // vector<pair<int, int>> mst;
    for (auto it : a)
    {
        int x = find(it[0]);
        int y = find(it[1]);
        if (x != y)
        {
            // mst.push_back({it[0], it[1]});
            c += it[2];
            unionn(it[0], it[1]);
        }
    }

    cout << c << endl;
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