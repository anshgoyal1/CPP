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
    sort(v.begin(), v.end());
    int diff = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        int x = v[i + 1] - v[i];
        diff = min(diff, x);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int x = v[i + 1] - v[i];
        if (x == diff)
        {
            cout << v[i] << " " << v[i + 1] << endl;
        }
    }
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