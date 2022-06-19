#include <bits/stdc++.h>
using namespace std;
#define int long long

int largest_subgrid(vector<vector<int>> &v, int maxSum)
{
    int n = v.size();
    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                sum[0][0] == v[0][0];
            }
            else if (i == 0)
            {
                sum[0][j] = sum[0][j - 1] + v[0][j];
            }
            else if (j == 0)
            {
                sum[i][0] = sum[i - 1][0] + v[i][0];
            }
            else
            {
                sum[i][j] = v[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
            mx = max(mx, sum[i][j]);
        }
    }

    int ans = 0;
    int l = 0;
    int r = n;
    while (l < r)
    {
        int x = l + (r - l + 1) / 2;
        int res = 0;

        for (int i = x - 1; i < n; i++)
        {
            for (int j = x - 1; j < n; j++)
            {
                int total = sum[i][j];
                if (i >= x)
                    total -= sum[i - x][j];
                if (j >= x)
                    total -= sum[i][j - x];

                if (i >= x && j >= x)
                    total -= sum[i - x][j - x];
                res = max(res, total);
            }
        }

        if (maxSum >= res)
            l = x;
        else
            r = x - 1;
    }

    cout << l << endl;
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