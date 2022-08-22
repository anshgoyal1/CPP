#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

int dp[105][100005];

int sol(vector<pair<int, int>> &v, int n, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if (v[n - 1].first > W)
    {
        return dp[n][W] = sol(v, n - 1, W);
    }

    return dp[n][W] = max(v[n - 1].second + sol(v, n - 1, W - v[n - 1].first), sol(v, n - 1, W));
}

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    memset(dp, -1, sizeof(dp));

    cout << sol(v, n, w) << endl;
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