#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

int dp[100005][3];

int sol(vector<vector<int>> &v, int n, int prev)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n][prev] != -1)
    {
        return dp[n][prev];
    }
    if (prev == 0)
    {
        return dp[n][prev] = max(v[n - 1][1] + sol(v, n - 1, 1), v[n - 1][2] + sol(v, n - 1, 2));
    }
    else if (prev == 1)
    {
        return dp[n][prev] = max(v[n - 1][0] + sol(v, n - 1, 0), v[n - 1][2] + sol(v, n - 1, 2));
    }
    else
    {
        return dp[n][prev] = max(v[n - 1][1] + sol(v, n - 1, 1), v[n - 1][0] + sol(v, n - 1, 0));
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    memset(dp, -1, sizeof(dp));
    int c1 = v[n - 1][0] + sol(v, n - 1, 0);
    int c2 = v[n - 1][1] + sol(v, n - 1, 1);
    int c3 = v[n - 1][2] + sol(v, n - 1, 2);

    cout << max({c1, c2, c3}) << endl;
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