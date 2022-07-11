#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int x, a, d, n;
    cin >> x >> a >> d >> n;
    if (d == 0)
    {
        cout << abs(x - a) << endl;
        return;
    }

    if (x > 0 && d < 0)
    {
        cout << x - a << endl;
        return;
    }
    int k = x - a;
    int p = k % d;
    cout << p << endl;
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