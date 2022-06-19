#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool odd = false;
    bool even = false;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            odd |= ((s[i - 1] - '0') % 2 == 1);
        }
        else
        {
            even |= ((s[i - 1] - '0') % 2 == 0);
        }
    }

    if (n % 2 == 1)
    {
        cout << (odd ? 1 : 2) << endl;
    }
    else
    {
        cout << (even ? 2 : 1) << endl;
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