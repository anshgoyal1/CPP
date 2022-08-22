// https://discord.com/channels/996058498657960006/996677310126235658/996677423909310576

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    int ans = 0;
    int i = 0;
    unordered_map<char, int> mp;
    while (i < n)
    {
        if (mp.find(s[i]) != mp.end())
        {
            ans++;
            mp.clear();
            mp[s[i]]++;
        }
        else
        {
            mp[s[i]]++;
            // i++;
        }
        i++;
    }
    if (!mp.empty())
    {
        ans++;
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