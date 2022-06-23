#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i - 1] < a[i - 1])
        {
            cout << dp[i - 1] << endl;
            return;
        }

        dp[i] = dp[i - 1] + a[i - 1];
    }

    cout << dp[n] << endl;
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