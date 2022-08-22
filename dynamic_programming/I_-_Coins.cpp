#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

double dp[3005][3005];
int vis[3005][3005];
vector<double> a;

double sol(int pos, int heads)
{
    if (heads < 0)
    {
        return 0.0;
    }

    if (pos == 0)
    {
        return (heads == 0);
    }

    if (vis[pos][heads])
    {
        return dp[pos][heads];
    }

    vis[pos][heads] = 1;

    return dp[pos][heads] = (a[pos - 1]) * sol(pos - 1, heads - 1) + (1.0 - a[pos - 1]) * sol(pos - 1, heads);
}

void solve()
{
    int n;
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    a = v;
    // memset(vis, -1, sizeof(vis));

    double ans = 0.0;

    for (int heads = 0; heads <= n; heads++)
    {
        int tails = n - heads;
        if (heads > tails)
            ans += sol(n, heads);
    }

    printf("%.9lf\n", ans);
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