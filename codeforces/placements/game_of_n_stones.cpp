#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 0;

    for (int i = 5; i <= n; i++)
    {
        if (!dp[i - 1] || !dp[i - 2] || !dp[i - 3])
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 0;
        }
    }

    cout << dp[n] << endl;
}