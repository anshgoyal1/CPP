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
    int i = 9;
    string res;

    while (i > 0 && n > i)
    {
        res += ('0' + i);
        n -= i;
        i--;
    }

    res += ('0' + n);
    reverse(res.begin(), res.end());
    cout << res << endl;
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