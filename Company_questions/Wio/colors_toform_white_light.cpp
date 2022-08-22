#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mp;
    for (int i = 0; i < m; i++)
    {
        int l, r, color;
        cin >> color >> l >> r;
        r++;
        if (mp.find(l) == mp.end())
        {
            mp[l] = vector<int>(4, 0);
        }
        if (mp.find(r) == mp.end())
        {
            mp[r] = vector<int>(4, 0);
        }

        mp[l][color]++;
        mp[r][color]--;
    }

    int ans = 0;
    int red = 0, blue = 0, green = 0;
    int prev = -1;

    for (auto it : mp)
    {
        red += it.second[1];
        blue += it.second[2];
        green += it.second[3];

        if (red > 0 && green > 0 && blue > 0)
        {
            if (prev == -1)
            {
                prev = it.first;
            }
        }
        else
        {
            if (prev != -1)
            {
                ans += (it.first - prev);
            }

            prev = -1;
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