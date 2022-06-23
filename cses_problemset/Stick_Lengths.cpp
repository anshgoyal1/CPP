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

    sort(a.begin(), a.end());

    int x = a[n / 2];
    int s1 = 0;
    for (auto it : a)
    {
        s1 += abs(it - x);
    }
    if (n % 2 == 0)
    {
        int s2 = 0;
        int x2 = a[n / 2 - 1];

        for (auto it : a)
        {
            s2 += abs(it - x2);
        }
        cout << min(s1, s2) << endl;
        return;
    }

    cout << s1 << endl;
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