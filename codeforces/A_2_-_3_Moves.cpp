#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 2 << endl;
        return;
    }
    if (n == 2 || n == 3)
    {
        cout << 1 << endl;
        return;
    }
    if (n == 4)
    {
        cout << 2 << endl;
        return;
    }
    if (n % 3 == 0)
    {
        cout << n / 3 << endl;
        return;
    }
    int x = n / 2;
    int a = n / 3;
    int b = n % 3;

    a++;
    cout << a << endl;
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