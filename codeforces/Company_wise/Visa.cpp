#include <bits/stdc++.h>
using namespace std;
#define int long long

void product_of_palindromes()
{
    string s;
    cin >> s;
    int n = s.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][i] = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            // cout << dp[i][j] << " ";
            ans = max(ans, dp[i][j] * dp[j + 1][n - 1]);
        }
        // cout << endl;
    }

    cout << ans << endl;
}

void football_game()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());

    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        auto it = upper_bound(a.begin(), a.end(), b[i]);
        if (it != a.end())
        {
            ans.push_back(it - a.begin());
        }
        else
        {
            ans.push_back(n);
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

void solve()
{
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