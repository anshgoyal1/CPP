#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int q;
    cin >> q;
    int l, r;
    while (q--)
    {
        cin >> l >> r;

        int x = lower_bound(v.begin(), v.end(), l) - v.begin();
        int y = upper_bound(v.begin(), v.end(), r) - v.begin();

        cout << y - x << " ";
    }
    cout << endl;
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