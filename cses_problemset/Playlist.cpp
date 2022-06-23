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

    int ans = 0;
    set<int> have;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n && !have.count(a[j]))
        {
            have.insert(a[j++]);
        }

        ans = max(ans, j - i);
        have.erase(a[i]);
    }

    cout << ans << endl;
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