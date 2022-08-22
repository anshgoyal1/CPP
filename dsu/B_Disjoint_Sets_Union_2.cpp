#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;

vector<int> parents;
vector<int> minimum;
vector<int> maximum;
vector<int> sz;

int find(int p)
{
    if (p == parents[p])
    {
        return p;
    }

    return p = find(parents[p]);
}

void get(int v)
{
    int a = find(v);
    int x = minimum[a];
    int y = maximum[a];
    int z = sz[a];

    cout << x << " " << y << " " << z << endl;
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
        parents[b] = a;
        minimum[a] = min(minimum[a], minimum[b]);
        maximum[a] = max(maximum[a], maximum[b]);
        sz[a] += sz[b];
    }
    else
    {
        parents[a] = b;
        minimum[b] = min(minimum[a], minimum[b]);
        maximum[b] = max(maximum[a], maximum[b]);
        sz[b] += sz[a];
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    parents.resize(n + 1);
    minimum.resize(n + 1);
    maximum.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parents[i] = i;
        minimum[i] = i;
        maximum[i] = i;
    }

    sz.resize(n + 1, 1);
    string s;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> s;

        if (s == "union")
        {
            cin >> u >> v;
            unionn(u, v);
        }
        else if (s == "get")
        {
            cin >> v;
            get(v);
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