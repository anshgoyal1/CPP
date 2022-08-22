#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

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

    int res = INT_MAX;
    bool is = false;
    for (int i = 0; i < m; i++)
    {
        initialize(n);
        int mi = a[i][2];
        int mx = INT_MIN;
        int cnt = 0;
        for (int j = i; j < m; j++)
        {
            int par1 = find(a[j][0]);
            int par2 = find(a[j][1]);
            if (par1 != par2)
            {
                cnt++;
                mx = max(mx, a[j][2]);
                unionn(a[j][0], a[j][1]);
            }
        }

        if (cnt == n - 1)
        {
            is = true;
            res = min(res, mx - mi);
        }
    }

    if (is)
    {
        cout << "YES" << endl;
        cout << res << endl;
    }
    else
    {
        NO;
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