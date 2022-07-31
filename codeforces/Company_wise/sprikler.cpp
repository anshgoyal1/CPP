#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int sol(int a, int b, int n, int sum, vector<vector<int>> &dp)
{
    if (sum > max(a, b))
    {
        return 0;
    }

    if (n == 0)
    {
        if (sum == a || sum == b)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    int c1 = sol(a, b, n - 1, sum + a, dp) % mod;
    int c2 = sol(a, b, n - 1, sum + b, dp) % mod;

    return dp[n][sum] = (c1 + c2) % mod;
}

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    vector<vector<int>> dp(n + 1, vector<int>(10, -1));

    cout << sol(a, b, n, 0, dp) << endl;
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