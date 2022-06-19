#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({a[i], b[i]});
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<pair<int, int>> res;
    bool fail = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (v[j] == make_pair(a[i], b[i]))
            {
                swap(v[i], v[j]);
                if (i != j)
                {
                    res.push_back({i, j});
                    break;
                }
            }
        }

        if (v[i] != make_pair(a[i], b[i]))
        {
            fail = true;
            break;
        }
    }

    if (fail)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res.size() << endl;
        for (auto p : res)
        {
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
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