#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin >> s;
    int d;
    cin >> d;
    int x, y;
    for (int i = 0; i < 3; i++)
    {
        cin >> x >> y;

        for (int i = x; i <= y; i++)
        {
            s[i] += 1;
        }
    }

    int ans = 0;
    for (auto it : s)
    {
        if (it - '0' >= d)
        {

            ans++;
        }
    }

    cout << ans << endl;
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