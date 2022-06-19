#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    vector<int> v(n);
    for (int &e : v)
    {
        cin >> e;
    }
    for (int &e : v)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            a.push_back(e);
        }
        else
        {
            b.push_back(e);
        }
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    ll curSumA = 0;
    int r = (int)b.size();
    ll curSumB = accumulate(b.begin(), b.end(), 0ll);
    int ans = INT_MAX;
    for (int l = 0; l <= a.size(); l++)
    {
        while (r > 0 && curSumA + curSumB - b[r - 1] >= m)
        {
            r--;
            curSumB -= b[r];
        }
        if (curSumB + curSumA >= m)
        {
            ans = min(ans, 2 * r + l);
        }
        if (l != a.size())
        {
            curSumA += a[l];
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
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