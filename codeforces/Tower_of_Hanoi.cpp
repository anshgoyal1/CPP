#include <bits/stdc++.h>
using namespace std;
#define int long long
void sol(int a, int b, int c, int n)
{
    if (n == 0)
        return;

    sol(a, c, b, n - 1);
    cout << a << " " << c << endl;
    sol(b, a, c, n - 1);
}
void solve()
{
    int n;
    cin >> n;
    cout << 2 * n - 1 << endl;
    sol(1, 2, 3, n);
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