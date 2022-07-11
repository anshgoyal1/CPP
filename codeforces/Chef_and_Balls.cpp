#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 1;
    char prev = s[0];

    for (int i = 1; i < n; i++)
    {
        if (s[i] != prev)
        {
            ans++;
        }
        prev = s[i];
    }

    cout << ans << endl;
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