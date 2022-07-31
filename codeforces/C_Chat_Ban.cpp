#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

int fun(int mid, int k)
{
    if (mid <= k)
    {
        return mid * (mid + 1) / 2;
    }

    return k * (k + 1) / 2 + (mid - k) * (k - 1 + k - (mid - k)) / 2;
}
void solve()
{
    int k, x;
    cin >> k >> x;

    if (x >= k * k)
    {
        cout << 2 * k - 1 << endl;
        return;
    }

    int l = 1;
    int r = 2 * k - 1;
    int ans = 2 * k - 1;
    bool over = false;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (fun(mid, k) <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    if (fun(ans, k) < x)
        cout << ans + 1 << endl;
    else
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