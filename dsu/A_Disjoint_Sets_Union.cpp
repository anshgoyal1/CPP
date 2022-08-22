#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;

vector<int> parents;
int find(int p)
{
    if (parents[p] == p)
    {
        return p;
    }

    return parents[p] = find(parents[p]);
}

bool get(int u, int v)
{
    int a = find(u);
    int b = find(v);

    return a == b;
}

void unionn(int u, int v, vector<int> &sz)
{
    int a = find(u);
    int b = find(v);

    if (a == b)
    {
        return;
    }

    if (sz[a] > sz[b])
    {
        parents[b] = a;
        sz[a] += sz[b];
    }
    else
    {
        parents[a] = b;
        sz[b] += sz[a];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    parents.resize(n);
    for (int i = 0; i < n; i++)
    {
        parents[i] = i;
    }

    vector<int> sz(n, 1);

    string s;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> u >> v;

        if (s == "union")
        {
            unionn(u, v, sz);
        }
        else
        {
            bool x = get(u, v);
            if (x)
            {
                YES;
            }
            else
            {
                NO;
            }
        }
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