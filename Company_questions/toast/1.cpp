// https://leetcode.com/discuss/interview-question/2400437/Toast-oror-SDE-intern-(OA)-oror-Minimum-Absolute-Sum

#include <bits/stdc++.h>
using namespace std;
#define int long long

int median(vector<int> &a)
{
    int n = a.size();

    if (n & 1)
    {
        return a[n / 2];
    }
    else
    {
        return (a[n / 2] + a[n / 2 - 1]) / 2;
    }
}

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
    int x = n / 2;
    vector<int> first;
    vector<int> second;
    for (int i = 0; i < x; i++)
    {
        first.push_back(v[i]);
    }

    for (int i = x; i < n; i++)
    {
        second.push_back(v[i]);
    }

    int k = median(first);
    int y = median(second);

    int ans = 0;

    for (auto it : v)
    {
        ans += (min(abs(it - k), abs(it - y)));
    }

    cout << ans << endl;
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