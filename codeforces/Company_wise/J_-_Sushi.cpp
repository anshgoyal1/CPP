#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;

double dp[305][305][305];

double sol(int x, int y, int z)
{
    if (dp[x][y][z] != -1)
    {
        return dp[x][y][z];
    }

    if (x == 0 && y == 0 && z == 0)
    {
        return dp[x][y][z] = 0.0;
    }

    int soma = x + y + z;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
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