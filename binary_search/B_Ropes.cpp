#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

bool help(double mid, int k, vector<double> &v)
{
    int c = 0;
    for (auto it : v)
    {
        c += (int)(it / mid);
    }

    return c >= k;
}
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    double l = 0.0;
    double r = 1e9;

    for (int i = 0; i < 100; i++)
    {
        double mid = (double)l + (double)(r - l) / 2;
        if (help(mid, k, v))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << fixed << setprecision(6) << l << endl;
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