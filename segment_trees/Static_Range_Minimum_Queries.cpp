#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

vector<int> seg;
int sz;

int combine(int a, int b)
{
    return min(a, b);
}
void build_tree(vector<int> &v, int l, int r, int pos)
{
    if (l == r)
    {

        seg[pos] = v[l];
        return;
    }

    int mid = (l + r) / 2;
    build_tree(v, l, mid, 2 * pos + 1);
    build_tree(v, mid + 1, r, 2 * pos + 2);
    seg[pos] = combine(seg[2 * pos + 1], seg[2 * pos + 2]);
}

int rangeQuery(int qlow, int qhigh, int l, int r, int pos)
{
    if (qlow <= l && qhigh >= r)
    {
        return seg[pos];
    }

    if (qlow > r || qhigh < l)
    {
        return INT_MAX;
    }

    int mid = (l + r) / 2;
    return combine(
        rangeQuery(qlow, qhigh, l, mid, 2 * pos + 1),
        rangeQuery(qlow, qhigh, mid + 1, r, 2 * pos + 2));
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    seg.resize(4 * n);
    sz = n;

    build_tree(v, 0, n - 1, 0);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;

        x--;
        y--;
        cout << rangeQuery(x, y, 0, n - 1, 0) << endl;
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