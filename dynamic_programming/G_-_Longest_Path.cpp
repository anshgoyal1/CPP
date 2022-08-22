#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

int dfs(int u, vector<int> adj[], vector<int> &dp)
{
    if (dp[u] != -1)
    {
        return dp[u];
    }

    int res = 0;
    for (auto it : adj[u])
    {
        res = max(res, 1 + dfs(it, adj, dp));
    }

    return dp[u] = res;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> dp(n + 1, -1);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, dfs(i, adj, dp));
    }
    cout << res << endl;
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