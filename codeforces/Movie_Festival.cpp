#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[x, y] : v)
    {
        cin >> y >> x;
    }
    sort(v.begin(), v.end());
    int curr = -1;
    int c = 0;
    for (auto &[x, y] : v)
    {
        if (y >= curr)
        {
            c++;
            curr = x;
        }
    }
    cout << c << endl;
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