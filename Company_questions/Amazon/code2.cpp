#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string a, b;
    cin >> a >> b;

    int cnt1[26] = {0};
    int cnt2[26] = {0};

    for (auto it : a)
    {
        cnt1[it - 'a']++;
    }

    for (auto it : b)
    {
        cnt2[it - 'a']++;
    }

    int ans = a.length();
    for (int i = 0; i < 26; i++)
    {
        if (cnt2[i] > 0)
        {
            ans = min(ans, cnt1[i] / cnt2[i]);
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