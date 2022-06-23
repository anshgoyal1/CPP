#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    int l = 0;
    int r = v.size() - 1;
    vector<pair<int, int>> ans;
    while (l < r)
    {
        int sum = v[l].first + v[r].first;

        if (sum == x)
        {
            pair<int, int> p = {v[l].second + 1, v[r].second + 1};

            if (p.first > p.second)
            {
                cout << p.second << " " << p.first << endl;
            }
            else
            {
                cout << p.first << " " << p.second << endl;
            }
            return;
        }
        else if (sum < x)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
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