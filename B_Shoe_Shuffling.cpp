#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]].push_back(i);
    }
    vector<int> res;
    for (auto it : m)
    {
        vector<int> v = it.second;
        int si = v.size();

        if (si == 1)
        {
            cout << -1 << endl;
            return;
        }

        sort(v.rbegin(), v.rend());

        if (si & 1)
        {
            swap(v[si / 2], v[0]);
        }
        for (auto it2 : v)
        {
            res.push_back(it2);
        }
    }
    for (auto it : res)
    {
        cout << it + 1 << " ";
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