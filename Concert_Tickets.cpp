#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int i, n, m;
    cin >> n >> m;
    multiset<int> s;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(-x);
    }

    while (m--)
    {
        int x;
        cin >> x;
        auto it = s.lower_bound(-x);
        if (it == s.end())
            cout << -1 << '\n';
        else
        {
            cout << -*it << '\n';
            s.erase(it);
        }
    }
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