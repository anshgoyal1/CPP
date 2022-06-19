#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    int neg = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] < 0)
        {
            neg++;
        }
    }

    for (int i = 0; i < neg; i++)
    {
        v[i] = -abs(v[i]);
    }

    for (int i = neg; i < n; i++)
    {
        v[i] = abs(v[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}