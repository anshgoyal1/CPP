#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

void solve(vector<string> &v, int n, int m)
{
    int sx = 0, sy = 0, ex = n - 1, ey = m - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if (v[i][j] == 'E')
            {
                ex = i;
                ey = j;
            }
        }
    }

    vector<vector<int>> minMoves(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, sx, sy});
    vector<int> dirs = {0, 1, 0, -1, 0};

    while (!pq.empty())
    {
        int x = pq.top()[1];
        int y = pq.top()[2];
        int moves = pq.top()[0];

        pq.pop();

        if (x == ex && y == ey)
        {
            cout << moves << endl;
            return;
        }

        if (moves >= minMoves[x][y])
        {
            continue;
        }

        minMoves[x][y] = moves;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j <= max(n, m); j++)
            {
                int nx = x + j * dirs[i];
                int ny = y + j * dirs[i + 1];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == '#')
                    break;

                int movesReq = 0;
                if (j == 1)
                {
                    movesReq = 1;
                }
                else
                {
                    movesReq = 2;
                }

                int newMoves = movesReq + moves;
                pq.push({newMoves, nx, ny});
            }
        }
    }
    cout << -1 << endl;
}
void code_likh_le()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
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

        code_likh_le();

    return 0;
}