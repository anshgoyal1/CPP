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

    vector<unsigned int> ans(n + 1);
    ans[0] = 1 << a[0];
    // cout << ans[0] << endl;

    for (int i = 1; i < n; i++)
    {
        ans[i] = ((1 << a[i]) | a[i - 1]);
    }

    cout << ans[n - 1] << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;

    // while (t--)
    solve();

    return 0;
}