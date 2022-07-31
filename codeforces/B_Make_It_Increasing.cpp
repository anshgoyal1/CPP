#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int c = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        while (a[i] >= a[i + 1] && a[i] > 0)
        {
            a[i] /= 2;
            c++;
        }

        if (a[i] == a[i + 1])
        {
            cout << -1 << endl;
            return;
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
    cin >> t;

    while (t--)

        solve();

    return 0;
}