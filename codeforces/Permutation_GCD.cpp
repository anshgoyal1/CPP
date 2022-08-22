#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;

void solve()
{
    int n, x;
    cin >> n >> x;
    int k = x % n + 1;
    if (k == x)
    {
        cout << -1 << endl;
        return;
    }

    cout << k << " ";

    for (int i = 1; i <= n; i++)
    {
        if (k != i)
        {
            cout << i << " ";
        }
    }
    cout << endl;
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