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

    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= 2 * n - i; j++)
        {
            if (v[i - 1] * v[j - 1] == i + j)
            {
                x++;
            }
        }
    }

    cout << x << endl;
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