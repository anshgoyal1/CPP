#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin >> s;
    int cnt[26] = {0};
    string x;
    for (auto it : s)
    {
        if (cnt[it - 'a'] == 0)
        {
            x += it;
        }
        cnt[it - 'a']++;
    }
    unordered_map<char, int> mp;
    int i = 1;
    int c = 1;
    for (auto it : x)
    {
        mp[it] = c;
        i++;
        if (i == 10)
        {
            i = 1;
            c++;
        }
    }

    int ans = 0;
    for (auto it : x)
    {
        ans += (cnt[it - 'a'] * mp[it]);
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