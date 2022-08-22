#include <bits/stdc++.h>
using namespace std;
#define int long long

int a;
int dfs(vector<vector<int>> &v, int i, int j)
{
    if (i < 0 || j < 0 || i >= a || j >= a || v[i][j] == 0 || v[i][j] == -1)
    {
        return 0;
    }

    if (i == a - 1 && j == a - 1)
    {
        return 1;
    }

    int ans = 0;
    v[i][j] = -1;
    ans += dfs(v, i + 1, j);
    ans += dfs(v, i, j + 1);
    v[i][j] = 1;
    return ans;
}
void solve()
{
    int b;
    cin >> a >> b;
    vector<vector<int>> v(a, vector<int>(a, 1));
    int c = a / 2;
    for (int i = c - b; i <= c + b; i++)
    {
        for (int j = c - b; j <= c + b; j++)
        {
            v[i][j] = 0;
        }
    }

    cout << dfs(v, 0, 0) << endl;
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