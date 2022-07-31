#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int c = 0;
    if (k == 1)
    {
        c = (n - 2) / 2;
        if ((n - 2) % 2 == 1)
            c++;

        cout << c << endl;
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (v[i] > v[i - 1] + v[i + 1])
            c++;
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