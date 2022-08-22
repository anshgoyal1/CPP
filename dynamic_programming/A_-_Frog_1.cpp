#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 2 * 1e9;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]), dp[i - 2] + abs(v[i] - v[i - 2]));
    }

    cout << dp[n - 1] << endl;
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