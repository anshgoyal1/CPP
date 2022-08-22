#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n, h, m;
    cin >> n >> h >> m;
    int mi = h * 60 + m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int time = x * 60 + y;
        if (time < mi)
        {
            time += 24 * 60;
        }
        v[i] = time;
    }

    sort(v.begin(), v.end());

    int mx = v[0];

    int diff = mx - mi;
    int hh = diff / 60;
    int hm = diff % 60;

    cout << hh << " " << hm << endl;
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