#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

int dfs(vector<string> v, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || i >= v.size() || j >= v[0]).size() || v[i][j] == '#' || v[i][j] == '*')
        {
            return 0;
        }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == v.size() - 1 && j == v[0].size() - 1)
    {
        return 1;
    }

    int ans = 0;
    v[i][j] = '#';
    ans += dfs(v, i + 1, j);
    ans += dfs(v, i, j + 1);

    v[i][j] = '.';
    return dp[i][j] = ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << dfs(v, 0, 0, dp) << endl;
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