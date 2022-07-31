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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int mn = *min_element(v.begin(), v.end());

    int i = 0;
    int k = n / 2;
    while (i < n && k)
    {
        if (v[i] != mn)
        {
            cout << v[i] << " " << mn << endl;
            k--;
        }
        i++;
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