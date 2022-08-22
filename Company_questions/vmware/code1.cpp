#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (ans.back() * v[i] <= k)
        {
            int x = ans.back();
            ans.pop_back();
            ans.push_back(x * v[i]);
        }
        else
        {
            ans.push_back(v[i]);
        }
    }

    for (auto kit : ans)
    {
        cout << kit << " ";
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