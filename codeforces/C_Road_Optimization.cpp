#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> dist(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> dist[i];
    }

    dist[n] = l;
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e17));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int m = 0; m < i; m++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] = min(dp[i][j], dp[m][j - 1] + cost[m] * (dist[i] - dist[m]));
            }
        }
    }
    int ans = 1e17;

    for (int i = n; i >= n - k; i--)
    {
        ans = min(ans, dp[n][i]);
    }

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