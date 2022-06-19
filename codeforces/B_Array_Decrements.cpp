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
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int mi = 100000000000;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > a[i])
        {
            cout << "NO" << endl;
            return;
        }
        if (b[i] != 0 && a[i] - b[i] < mi)
        {
            mi = a[i] - b[i];
        }
    }
    for (int i = 0; i < n; i++)
    {

        if (mi < a[i] - b[i])
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

    int t = 1;
    cin >> t;

    while (t--)

        solve();

    return 0;
}