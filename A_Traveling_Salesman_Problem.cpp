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
    int x, y;
    int minX = 0;
    int maxX = 0;
    int minY = 0;
    int maxY = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    minX = abs(minX);
    minY = abs(minY);
    maxX = abs(maxX);
    maxY = abs(maxY);
    int ans1 = 2 * (maxX + minX) + 2 * minY + 2 * maxY;
    int ans2 = 2 * (maxY + minY) + 2 * minX + 2 * maxX;

    cout << min(ans1, ans2) << endl;
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