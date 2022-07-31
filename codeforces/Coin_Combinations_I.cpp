#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;
const int mod = 1e9 + 7;
int x;
int helper(vector<int> &v, int n, int c, vector<vector<int>> &dp)
{
    if (c == 0)
    {
        return (x - n + 1);
    }

    if (n == 0 && c != 0)
    {
        return 0;
    }

    if (dp[n][c] != -1)
    {
        return dp[n][c];
    }

    if (c < v[n - 1])
    {
        return dp[n][c] = helper(v, n - 1, c, dp) % mod;
    }

    return dp[n][c] = (helper(v, n - 1, c, dp) + helper(v, n, c - v[n - 1], dp)) % mod;
}
void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    x = n;
    vector<vector<int>> dp(n + 1, vector<int>(c + 1, -1));

    int ans = helper(v, n, c, dp) % mod;
    cout << ans % mod << endl;
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