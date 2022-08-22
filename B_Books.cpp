#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

int help(vector<int> &v, int mid, int k)
{
    int x = 0;
    for (int i = mid; i < v.size(); i++)
    {
        x += v[i];
    }

    return (x <= k);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // sort(v.begin(), v.end());
    int l = 0;
    int r = n;
    int ans = -1;

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (help(v, mid, k))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << n - l << endl;
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