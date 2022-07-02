#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(string s, int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (s[0] == '0')
    {
        return 0;
    }

    int count = 0;

    if (s[n - 1] > '0')
    {
        count += solve(s, n - 1);
    }

    if (s[n - 2] == '1' || (s[n - 2] == '2' && s[n - 1] < '7'))
    {
        count += solve(s, n - 2);
    }
    return count;
}

int count(string s)
{
    if (s.empty() || (s.length() == 1 && s[0] == '0'))
    {
        return 0;
    }
    int n = s.length();

    return solve(s, n);
}

void solve()
{
    string s;
    cin >> s;
    cout << count(s);
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