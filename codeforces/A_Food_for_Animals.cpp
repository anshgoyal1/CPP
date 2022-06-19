#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int p = 0;
    if (a < x)
    {
        p = x - a;
    }
    int q = 0;
    if (b < y)
    {
        q = y - b;
    }

    if (p + q <= c)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}