#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > k)
        {
            break;
        }

        int x = k - a[i];
        int y = *lower_bound(b.begin(), b.end(), x);

                if (a[i] + y <= k)
        {
            sum = max(a[i] + y, sum);
        }
    }

    cout << sum << endl;
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

// https://leetcode.com/discuss/interview-question/2403779/DE-Shaw-or-OA-or-Pair-Selection