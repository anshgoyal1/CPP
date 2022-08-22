#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {

        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int x = n - v[m - 1];
    x += v[0] - 1;

    vector<int> diff;
    diff.push_back(x);
    for (int i = 0; i < m - 1; i++)
    {
        diff.push_back(v[i + 1] - v[i] - 1);
    }

    sort(diff.rbegin(), diff.rend());

    // for (auto it : diff)
    // {
    //     cout << it << " ";
    // }

    // cout << endl;

    int c = 0;
    int d = 0;
    for (int i = 0; i < diff.size(); i++)
    {
        int x = max(0LL, diff[i] - d);
        if (x == 1)
        {
            c += 1;
            d += 2;
        }
        else if (x > 0)
        {
            c += x - 1;
            d += 4;
        }
    }

    cout << n - c << endl;
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