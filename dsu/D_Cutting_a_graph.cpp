#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;

vector<int> parent;
vector<int> sz;

int find(int u)
{
    if (u == parent[u])
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
        parent[b] = a;
        sz[a] += sz[b];
    }
    else
    {
        parent[a] = b;
        sz[b] += sz[a];
    }
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    parent.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    vector<pair<string, pair<int, int>>> que(q);
    string s;
    int u, v;
    for (int i = 0; i < q; i++)
    {
        cin >> s >> u >> v;

        que[i] = {s, {u, v}};
    }

    vector<string> ans;
    for (int i = q - 1; i >= 0; i--)
    {
        if (que[i].first == "ask")
        {
            int par1 = find(que[i].second.first);
            int par2 = find(que[i].second.second);

            if (par1 == par2)
            {
                ans.push_back("YES");
            }
            else
            {
                ans.push_back("NO");
            }
        }
        else
        {
            unionn(que[i].second.first, que[i].second.second);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans)
    {
        cout << it << endl;
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