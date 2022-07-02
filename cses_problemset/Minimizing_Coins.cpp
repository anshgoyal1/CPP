#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[101][1000001];

int helper(vector<int> &coins, int n, int amount)
{
    if (amount == 0)
    {
        return 0;
    }

    if (amount < 0 || n < 0)
    {
        return 1e8;
    }

    if (dp[n][amount] != -1)
    {
        return dp[n][amount];
    }

    return dp[n][amount] = min(helper(coins, n - 1, amount),
                               1 + helper(coins, n, amount - coins[n]));
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));

    int d = helper(a, n - 1, x);
    int k = d >= 1e6 ? -1 : d;
    cout << k << endl;
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