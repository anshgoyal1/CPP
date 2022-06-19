#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int m = (n - 3) / 3;

    if (n % 3 == 0)
    {
        cout << m + 1 << " " << m + 2 << " " << m << endl;
    }
    else if (n % 3 == 1)
    {
        cout << m + 1 << " " << m + 3 << " " << m << endl;
    }
    else if (n % 3 == 2)
    {
        cout << m + 2 << " " << m + 3 << " " << m << endl;
    }
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