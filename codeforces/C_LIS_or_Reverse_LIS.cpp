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

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }

    int cnt = 0;
    for (auto it : m)
    {
        cnt += min((int)2, it.second);
    }
    int ans = (cnt + 1) / 2;
    cout << ans << endl;
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