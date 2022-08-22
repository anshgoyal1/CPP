#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    string x = a;
    int i = 0;
    while (a.size() > m)
    {
        a[i + 1] = min(a[i + 1], a[i]);
        a.erase(a.begin());
    }
    i = 0;
    while (x.size() > m)
    {
        x[i + 1] = max(x[i + 1], x[i]);
        x.erase(x.begin());
    }

    // cout << a << " " << x << endl;
    if (a == b || x == b)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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