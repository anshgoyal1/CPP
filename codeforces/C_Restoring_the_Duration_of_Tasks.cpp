#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> d;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            d.push_back(b[i] - a[i]);
        }
        else
        {
            d.push_back(b[i] - max(a[i], b[i - 1]));
        }
    }

    for (auto it : d)
    {
        cout << it << " ";
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