#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'W')
        {
            ans++;
        }
    }
    int j = 0;
    int x = ans;
    for (int i = k; i < n; i++)
    {
        if (s[i] == 'W' && s[i - k] == 'B')
        {
            ans++;
        }
        else if (s[i] == 'B' && s[i - k] == 'W')
        {
            ans--;
        }
        x = min(ans, x);
    }

    cout << x << endl;
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