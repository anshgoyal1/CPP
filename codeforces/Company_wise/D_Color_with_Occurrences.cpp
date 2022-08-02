#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    map<string, int> mp;
    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        mp[temp] = i;
    }

    int n = s.size();

    int dp[n + 1];
    int par[n + 1];
    int idx[n + 1];
    int Mi[n + 1];

    for (int i = 0; i <= n; i++)
    {
        par[i] = idx[i] = -1;
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;

        string temp;
        int mi = i + 1;
        for (int j = i; j >= 1; j--)
        {
            temp.insert(temp.begin(), s[j - 1]);
            if (mp.find(temp) != mp.end())
            {
                idx[i] = mp[temp];
                Mi[i] = j;
                mi = min(mi, j);
            }

            if (temp.size() > 10)
            {
                break;
            }
        }

        for (int j = i; j >= mi; j--)
        {
            int val = dp[j - 1] + 1;
            if (val < dp[i])
            {
                par[i] = j - 1;
            }

            dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }

    if (dp[n] == INT_MAX)
    {
        cout << -1 << endl;
        return;
    }

    int pos = n;
    vector<pair<int, int>> vp;
    while (pos > 0)
    {
        int p = par[pos];
        vp.push_back({idx[pos], Mi[pos]});
        pos = p;
    }

    cout << dp[n] << endl;
    for (pair<int, int> p : vp)
    {
        cout << p.first + 1 << " " << p.second << endl;
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