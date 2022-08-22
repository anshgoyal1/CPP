#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

vector<vector<int>> seg;
int n, m;
vector<vector<int>> a;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry)
{
    if (ly == ry)
    {
        if (lx == rx)
        {
            seg[vx][vy] = a[lx][ly];
        }
        else
        {
            seg[vx][vy] = seg[2 * vx + 1][vy] + seg[2 * vx + 2][vy];
        }
    }
    else
    {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, 2 * vy + 1, ly, my);
        build_y(vx, lx, rx, 2 * vy + 2, my + 1, ry);
        seg[vx][vy] = seg[vx][vy * 2 + 1] + seg[vx][2 * vy + 2];
    }
}

void build_x(int vx, int lx, int rx)
{
    if (lx != rx)
    {
        int mx = (lx + rx) / 2;
        build_x(2 * vx + 1, lx, mx);
        build_x(2 * vx + 2, mx + 1, rx);
    }

    build_y(vx, lx, rx, 0, 0, m - 1);
}

int sum_y(int vx, int vy, int tly, int try_, int ly, int ry)
{
    if (ly > ry)
    {
        return 0;
    }

    if (ly == tly and try_ == ry)
    {
        return seg[vx][vy];
    }

    int tmy = (try_ + tly) / 2;

    return sum_y(vx, 2 * vy + 1, tly, tmy, ly, min(ry, tmy)) +
           sum_y(vx, 2 * vy + 2, tmy + 1, try_, max(ly, tmy + 1), ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry)
{
    if (lx > rx)
    {
        return 0;
    }

    if (lx == tlx and rx == trx)
    {
        return sum_y(vx, 0, 0, m - 1, ly, ry);
    }

    int tmx = (tlx + trx) / 2;
    return sum_x(2 * vx + 1, tlx, tmx, lx, min(rx, tmx), ly, ry) +
           sum_x(2 * vx + 2, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
}

void solve()
{
    int q;
    cin >> n >> q;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> b(n, vector<int>(v[0].size()));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            b[i][j] = v[i][j] == '.' ? 0 : 1;
        }
    }

    a = b;
    m = v[0].size();
    seg.resize(4 * n, vector<int>(4 * m));

    build_x(0, 0, n - 1);
    int x1, x2, y1, y2;
    for (int i = 0; i < q; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        cout << sum_x(0, 0, n - 1, x1, x2, y1, y2) << endl;
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