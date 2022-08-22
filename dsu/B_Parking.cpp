#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

vector<int> parent;
vector<int> sz;

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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans(n);
    initialize(n);
    for (int i = 0; i < n; i++)
    {
        int it = v[i];
        int u = it;
        int x = find(u);
        int v = (x + 1);
        int y;
        if (v == n + 1)
        {
            y = find(1);
        }
        else
        {
            y = find(v);
        }
        cout << x << " ";
        parent[x] = y;
    }

    // for (auto it : parent)
    // {
    //     cout << it << " ";
    // }
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