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

void initialize(int n)
{
    parent.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a;
    int u, v, w;
    for (int i = 0; i < k; i++)
    {
        cin >> u >> v >> w;
        a.push_back({u, v, w});
    }

    initialize(n);
    int mi = INT_MIN;

    sort(a.begin(), a.end(), comp);

    for (auto it : a)
    {
        int x = find(it[0]);
        int y = find(it[1]);

        if (x != y)
        {
            mi = max(mi, it[2]);
            unionn(it[0], it[1]);
        }
    }

    cout << mi << endl;
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