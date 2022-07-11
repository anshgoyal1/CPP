#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max_ending_here = INT_MIN;
    int max_so_far = 0;

    for (int i = 0; i < n; i++)
    {
        max_so_far += a[i];

        if (max_so_far > max_ending_here)
        {
            max_ending_here = max_so_far;
        }

        if (max_so_far < 0)
        {
            max_so_far = 0;
        }
    }
    cout << max_ending_here << endl;
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