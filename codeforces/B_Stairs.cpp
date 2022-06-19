#include <bits/stdc++.h>
using namespace std;
#define int long long
int getX(int x)
{
    return x * (x + 1) / 2;
}
void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; (getX((1LL << i) - 1)) <= n; i++)
    {
        ans++;
        n -= (getX((1LL << i) - 1));
    }

    cout << ans << endl;
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