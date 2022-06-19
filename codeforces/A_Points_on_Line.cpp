#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int j = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        while (a[i] - a[j] > d & j < i)
            j++;

        ans += (long long)(i - j) * (i - j - 1) / 2;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;

    // while (t--)
    // {
    solve();
    // }

    return 0;
}