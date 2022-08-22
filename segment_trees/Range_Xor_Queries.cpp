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
    return a ^ b;
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

int query(int low, int high, int l, int r, int pos)
{
    if (low <= l && high >= r)
    {
        return seg[pos];
    }

    if (low > r || high < l)
    {
        return 0;
    }

    int mid = (l + r) / 2;
    return combine(query(low, high, l, mid, 2 * pos + 1),
                   query(low, high, mid + 1, r, 2 * pos + 2));
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

    int x, y;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        cout << query(x, y, 0, n - 1, 0) << endl;
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