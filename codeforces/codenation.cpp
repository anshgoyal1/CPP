#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    if (n % 2 == 0 && m % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        int x = 0;
        if (n % 2 == 0)
        {
            for (auto it : a)
            {
                x ^= it;
            }
        }
        else if (m % 2 == 0)
        {
            for (auto it : b)
            {
                x ^= it;
            }
        }
        else
        {
            for (auto it : a)
            {
                x ^= it;
            }

            for (auto it : b)
            {
                x ^= it;
            }
        }

        cout << x << endl;
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