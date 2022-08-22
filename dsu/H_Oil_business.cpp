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
    return a[2] > b[2];
}

bool comp2(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
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
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> a(m);
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        a[i] = {u, v, w, i};
    }

    sort(a.begin(), a.end(), comp);
    initialize(n);
    int c = 0;

    vector<pair<int, int>> ans;

    for (auto it : a)
    {
        int x = find(it[0]);
        int y = find(it[1]);

        if (x != y)
        {
            unionn(it[0], it[1]);
        }
        else
        {
            c += it[2];
            ans.push_back({it[2], it[3] + 1});
        }
    }

    sort(ans.begin(), ans.end());

    while (!ans.empty() && c > x)
    {
        c -= ans.back().first;
        ans.pop_back();
    }

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end(), comp2);
    for (auto it : ans)
    {
        cout << it.second << " ";
    }
    cout << endl;
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