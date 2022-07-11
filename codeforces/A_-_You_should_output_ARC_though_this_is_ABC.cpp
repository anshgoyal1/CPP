#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(2, vector<int>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << v[r - 1][c - 1] << endl;
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