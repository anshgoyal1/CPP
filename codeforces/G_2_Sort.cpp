#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int res = 0;
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] >= v[i] * 2)
        {
            res += max(len - k + 1, 0LL);
            len = 1;
        }
        else
            len++;
    }
    res += max(len - k + 1, 0LL);
    cout << res << endl;
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
