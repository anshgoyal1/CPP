#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int x1, p1;
    cin >> x1 >> p1;
    int x2, p2;
    cin >> x2 >> p2;

    int mn = min(p1, p2);
    p1 -= mn;
    p2 -= mn;

    if (p1 >= 7)
    {
        cout << ">" << endl;
    }
    else if (p2 >= 7)
    {
        cout << "<" << endl;
    }
    else
    {
        while (p1--)
        {
            x1 *= 10;
        }
        while (p2--)
        {
            x2 *= 10;
        }

        if (x1 > x2)
        {
            cout << ">" << endl;
        }
        else if (x1 < x2)
        {
            cout << "<" << endl;
        }
        else
        {
            cout << "=" << endl;
        }
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