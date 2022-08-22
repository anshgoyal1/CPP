#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

int n, x, y;

bool help(int mid)
{
    int temp = mid / x + mid / y;

    return temp >= n - 1;
}

void solve()
{

    cin >> n >> x >> y;

    int l = 0;
    int r = 1e9;

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (help(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l + min(x, y) << endl;
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