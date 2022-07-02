#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[20][180][2];

void getDigits(int n, vector<int> &digits)
{
    while (n > 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
}

int solve(int idx, int sum, int tight, vector<int> digits)
{
    if (idx == -1)
    {
        return sum;
    }

    if (dp[idx][sum][tight] != -1 && tight != 1)
    {
        return dp[idx][sum][tight];
    }

    int ret = 0;

    int k = tight ? digits[idx] : 9;

    for (int i = 0; i <= k; i++)
    {
        int newTight = (digits[idx] == i) ? tight : 0;

        ret += solve(idx - 1, sum + i, newTight, digits);
    }

    if (!tight)
    {
        dp[idx][sum][tight] = ret;
    }
    return ret;
}

int rangeDigitSum(int a, int b)
{
    memset(dp, -1, sizeof(dp));

    vector<int> digitA;
    getDigits(a - 1, digitA);

    int ans1 = solve(digitA.size() - 1, 0, 1, digitA);

    vector<int> digitB;
    getDigits(b, digitB);

    int ans2 = solve(digitB.size() - 1, 0, 1, digitB);

    return ans2 - ans1;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    cout << rangeDigitSum(a, b) << endl;
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