#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    x -= a;
    y -= b;

    if (x <= 0 && y <= 0)
    {
        cout << "YES" << endl;
    }
    else if (max(x, 0LL) + max(y, 0LL) <= c)
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

    int t = 1;
    cin >> t;

    while (t--)

        solve();

    return 0;
}