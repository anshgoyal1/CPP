#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

int w, h, n;

bool help(int mid)
{
    int x = mid / w;
    int y = mid / h;

    int temp = x * y;
    if (temp >= n)
    {
        return true;
    }
    return false;
}
void solve()
{

    cin >> w >> h >> n;

    int l = 1;
    int r = w * h * n;

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
    cout << l << endl;
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