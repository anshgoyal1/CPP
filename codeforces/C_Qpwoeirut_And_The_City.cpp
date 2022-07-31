#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

int sol(vector<int> &v, int n, int i, int l, vector<int> &dp)
{
    if (l == 0)
    {
        return INT_MAX;
    }
    if (i == n - 1)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int mx = max(v[i - 1], v[i + 1]);

    int c1 = sol(v, n, i + 1, l, dp);
    int c2 = mx + 1 + sol(v, n, i + 1, l - 1, dp);

    return dp[i] = min(c1, c2);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int l = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (v[i] <= v[i - 1] || v[i] <= v[i + 1])
        {
            l++;
        }
    }
    vector<int> dp(n + 1, -1);
    cout << sol(v, n, 1, l, dp) << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)

        solve();

    return 0;
}