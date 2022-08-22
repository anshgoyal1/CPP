#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n, w;
    cin >> n >> w;
    int x = 0;
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
        x += v[i].second;
    }

    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int item = 1; item <= n; item++)
    {
        int weight = v[item].first;
        int value = v[item].second;

        for (int i = x; i >= value; i--)
        {
            dp[i] = min(dp[i], dp[i - value] + weight);
        }
    }

    for (int i = x; i >= 0; i--)
    {
        if (dp[i] <= w)
        {
            cout << i << endl;
            break;
        }
    }
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