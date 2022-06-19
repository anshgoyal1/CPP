#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
vector<bool> vis(100005, false);

void dfs(int i)
{
    vis[i] = true;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int u;
    for (int i = 0; i < n; i++)
    {
        cin >> u;
        u--;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ans++;
            dfs(i);
        }
    }

    cout << ans << endl;
}