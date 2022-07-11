#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int diff = b - a;

    if (diff < 0)
    {
        cout << "-1" << endl;
        return;
    }
    else if (diff == 0)
    {
        cout << "1" << endl;
        return;
    }
    int ans = 1;
    ans += (diff / (c / 2));
    // ans += ((diff % (c / 2)) == 0 ? 0 : 1);
    cout << ans << endl;
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