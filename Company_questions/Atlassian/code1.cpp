#include <bits/stdc++.h>
using namespace std;
#define int long long

int indicator(vector<int> &v, int x)
{
    int n = v.size();
    int c = 0;
    int prev = -1;
    int cnt = 1;
    for (int i = x; i < n; i++)
    {
        if (v[i] == prev)
        {
            cnt++;
        }
        else
        {
            if (cnt == prev)
            {
                c++;
                // cout << prev << endl;
            }
            cnt = 1;
        }
        prev = v[i];
    }
    if (cnt == prev)
        c++;
    return c;
}

int indicator1(vector<int> &v)
{
    return indicator(v, 0);
}

int indicator2(vector<int> &v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        // int idx = it - 1;
        ans += indicator(v, i) ? 1 : 0;
    }
    return ans;
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

    // for (auto it : v)
    // {
    //     cout << it << " ";
    // }

    cout << indicator2(v) << endl;
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