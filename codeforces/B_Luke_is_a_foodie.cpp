#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // for (auto it : v)
    // {
    //     cout << it << " ";
    // }

    // cout << endl;

    int mn = v[0];
    int mx = v[0];
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
        // cout << mx << " " << mn << endl;
        if (abs(mx - mn) > 2 * x)
        {
            c++;
            mx = v[i];
            mn = v[i];
        }
    }

    cout << c << endl;
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