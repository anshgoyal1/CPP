#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans(n + 1, 0);
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(v[i]) == mp.end())
        {
            mp[v[i]].push_back(i);
        }
        else if (mp[v[i]].back() % 2 != i % 2)
        {
            mp[v[i]].push_back(i);
        }
    }

    for (auto it : mp)
    {
        ans[it.first - 1] = it.second.size();
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
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