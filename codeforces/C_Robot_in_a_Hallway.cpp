#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
int m;

int dfs(vector<vector<int>> &v, vector<vector<int>> &vis, int i, int j, set<pair<int, int>> &st)
{
    if (i < 0 || j < 0 || i >= 2 || j >= m)
    {
        return INT_MAX;
    }

    if (st.find({i, j}) != st.end())
    {
        return INT_MAX;
    }

    if (st.size() == 2 * m)
    {
        return v[i][j];
    }
    if (vis[i][j] != -1)
    {
        return vis[i][j];
    }

    st.insert({i, j});

    int d1 = dfs(v, vis, i + 1, j, st);
    int d2 = dfs(v, vis, i - 1, j, st);
    int d3 = dfs(v, vis, i, j + 1, st);
    int d4 = dfs(v, vis, i, j - 1, st);
}

void solve()
{

    cin >> m;
    vector<vector<int>> v(2, vector<int>(m));
    int mx = INT_MIN;
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> v[j][i];
            mx = max(mx, v[j][i]);
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)

        solve();

    return 0;
}