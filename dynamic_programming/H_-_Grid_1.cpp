#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;
const int mod = 1e9 + 7;

int dfs(vector<string> &v, int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i >= n || j >= m || v[i][j] == '#' || v[i][j] == '$')
    {
        return 0;
    }

    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    v[i][j] = '$';
    ans = (ans + dfs(v, i + 1, j, n, m, dp) % mod) % mod;
    ans = (ans + dfs(v, i, j + 1, n, m, dp) % mod) % mod;

    v[i][j] = '.';
    return dp[i][j] = ans % mod;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << dfs(v, 0, 0, n, m, dp) % mod << endl;
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