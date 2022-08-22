#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    cout << m - j << endl;
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