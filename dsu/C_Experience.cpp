#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;

vector<int> parent;
vector<int> sz;
vector<int> marks;

pair<int, int> find(int u)
{
    if (u == parent[u])
    {
        return {u, marks[u]};
    }

    auto par = find(parent[u]);
    parent[u] = par.first;
    marks[u] += par.second - marks[par.first];
    return {parent[u], marks[u] + marks[parent[u]]};
}

void unionn(int u, int v)
{
    int a = find(u).first;
    int b = find(v).first;

    if (a == b)
    {
        return;
    }

    if (sz[a] > sz[b])
    {
        parent[b] = a;
        sz[a] += sz[b];
        marks[b] -= marks[a];
    }
    else
    {
        parent[a] = b;
        sz[b] += sz[a];
        marks[a] -= marks[b];
    }
}

void add(int u, int val)
{
    int a = find(u).first;

    marks[a] += val;
}

int get(int u)
{
    int a = find(u).second;

    return a;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    sz.resize(n + 1, 1);
    marks.resize(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    string s;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> u >> v;
            add(u, v);
        }
        else if (s == "join")
        {
            cin >> u >> v;
            unionn(u, v);
        }
        else
        {
            cin >> u;
            cout << get(u) << endl;
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