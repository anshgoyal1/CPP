#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1005][1005][10];
int number_of_palindromic(string s, int i, int j, int k)
{
    if (k == 0)
    {
        return 0;
    }

    if (i > j)
    {
        return 0;
    }
    if (k == 1)
    {
        return j - i + 1;
    }

    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }
    int res = 0;
    if (s[i] == s[j] && i < j)
    {
        res = number_of_palindromic(s, i + 1, j - 1, k - 2);
    }

    res += number_of_palindromic(s, i + 1, j, k) + number_of_palindromic(s, i, j - 1, k) -
           number_of_palindromic(s, i + 1, j - 1, k);
    return dp[i][j][k] = res;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    memset(dp, -1, sizeof(dp));
    cout << number_of_palindromic(s, 0, n - 1, 5) << endl;
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