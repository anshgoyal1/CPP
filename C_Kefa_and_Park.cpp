#include <bits/stdc++.h>
using namespace std;

#define Size 100010
long long n, m, total = 0;
bool vis[Size];
vector<long long int> adj[Size];
vector<long long int> a(Size);

void dfs(long long s, long long sum)
{
    if (vis[s])
        return;

    vis[s] = 1;
    if (a[s])
    {
        sum++;
    }
    else
    {
        sum = 0;
    }

    if (sum > m)
    {
        return;
    }

    if (s != 1 && adj[s].size() == 1)
    {
        total++;
    }

    for (int i = 0; i < adj[s].size(); i++)
    {
        dfs(adj[s][i], sum);
    }
}

int main()
{
    cin >> n >> m;

    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    long long x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);
    cout << total << endl;
}