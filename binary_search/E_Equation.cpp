#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

void solve()
{
    double c;
    cin >> c;

    double l = 0.0;
    double r = 1e9;

    for (int i = 0; i < 100; i++)
    {
        double mid = (double)l + (double)(r - l) / 2;
        double sq = pow(mid, 2);
        double root = sqrt(mid);
        double x = sq + root;
        if (abs(x - c) <= 1e-6)
        {
            cout << fixed << setprecision(6) << mid << endl;
            return;
        }
        else if (x > c)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
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