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

    initialize(n);

    char c;
    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> c >> x;
        int a = find(x);
        if (c == '-')
        {

            if (x == n)
            {
                parent[x] = 0;
            }
            else
            {
                parent[a] = parent[a + 1];
            }
        }
        else if (c == '?')
        {

            if (a == 0)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << a << '\n';
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