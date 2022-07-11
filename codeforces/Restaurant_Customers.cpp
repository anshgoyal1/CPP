#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> b(n);
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v[i] = x;
        b[i] = y;
    }

    sort(v.begin(), v.end());
    sort(b.begin(), b.end());

    int c = 0;
    int max_c = 0;
    x = 0;
    y = 0;

    while (x < n)
    {
        if (v[x] < b[y])
        {
            c++;
            x++;
        }
        else
        {
            c--;
            y++;
        }

        max_c = max(max_c, c);
    }

    cout << max_c << endl;
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