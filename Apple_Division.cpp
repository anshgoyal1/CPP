#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int ans = LLONG_MAX;
    for (int i = 0; i < pow(2, n); i++)
    {
        int sum1 = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum1 += a[j];
            }
        }

        ans = min(ans, abs(sum - 2 * sum1));
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