#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int x = 4 - (n % 4);
    // cout << n % 4 << endl;
    if (x == 4)
    {
        cout << 0 << endl;
    }
    else if (x == 1)
    {
        cout << min(1 * a, min(3 * c, 1 * c + 1 * b)) << endl;
    }
    else if (x == 2)
    {
        cout << min(a * 2, min(1 * b, 2 * c)) << endl;
    }
    else
    {
        cout << min(a * 3, min(1 * a + 1 * b, 1 * c));
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;

    // while (t--)

    solve();

    return 0;
}