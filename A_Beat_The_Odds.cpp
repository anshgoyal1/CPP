#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
        {
            c++;
        }
    }

    cout << min(c, n - c ) << endl;
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