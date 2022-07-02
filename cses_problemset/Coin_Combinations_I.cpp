#include <bits/stdc++.h>
using namespace std;
// #define int long long

int dp[105][1000005];
int helper(vector<int> &coins, int n, int amount)
{
    if (n == 0)
    {
        return 0;
    }

    if (amount == 0)
    {
        return 1;
    }

    if (dp[n][amount] != -1)
    {
        return dp[n][amount];
    }

    if (coins[n - 1] > amount)
    {
        return dp[n][amount] = helper(coins, n - 1, amount);
    }

    return dp[n][amount] =
               helper(coins, n, amount - coins[n - 1]) +
               helper(coins, n - 1, amount);
}
int change(int amount, vector<int> &coins)
{
    memset(dp, -1, sizeof(dp));

    int n = coins.size();
    if (amount == 0)
    {
        return 1;
    }
    if (n == 0)
        return 0;
    int ans = helper(coins, n, amount);
    return ans;
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

    int ans = change(x, a);
    cout << ans << endl;
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