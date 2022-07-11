#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l, r;
    cin >> l >> r;
    int x = (r - l) / n;
    int a = l % n;
    int b = r % n;

    int c = 0;
    for (int i = a; i <= b; i++)
    {
        int idx = i % n;
        if (s[idx] == 'c')
        {
            c++;
        }
    }

    int ans = x * c + c;
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)

        solve();

    return 0;
}