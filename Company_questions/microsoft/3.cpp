// https://cdn.discordapp.com/attachments/998953984821841971/998954670183678042/WhatsApp_Image_2022-07-19_at_7.30.39_PM.jpeg

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j])
            {
                q.push({i, j});
            }
        }
    }

    vector<int> dirs = {0, 1, 0, -1, 0};
    vector<vector<int>> matrix(n, vector<int>(m, 0));

    while (!q.empty() && k--)
    {
        int sz = q.size();

        while (sz--)
        {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];

                if (nx < 0 or ny < 0 or nx >= n or ny >= m or grid[nx][ny] == 1)
                {
                    continue;
                }

                grid[nx][ny] = 1;
                matrix[nx][ny]++;
                q.push({nx, ny});
            }
        }
    }

    for (auto it : matrix)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
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