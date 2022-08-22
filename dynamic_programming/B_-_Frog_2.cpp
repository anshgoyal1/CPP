#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(n, INT_MAX);
    // dp[1] = abs(v[1] - v[0]);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= i + k; j++)
        {
            if (j < n)
            {
                dp[j] = min(dp[j], dp[i] + abs(v[j] - v[i]));
            }
        }
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