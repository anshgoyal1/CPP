#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;

int dp[100005];

int sol(int k, vector<int> &v)
{
    if (dp[k] != -1)
        return dp[k];

    if (k == 0)
        return 0;

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > k)
            continue;

        if (sol(k - v[i], v) == 0)
        {
            ans = 1;
            break;
        }
    }

    return dp[k] = ans;
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

    memset(dp, -1, sizeof(dp));

    if (sol(k, v))
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
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