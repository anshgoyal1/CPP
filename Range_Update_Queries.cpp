#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

vector<int> seg;
int sz;

void build_tree(vector<int> &v, int pos, int tl, int tr)
{
    if (tl == tr)
    {
        seg[pos] = v[tl];
        return;
    }

    int mid = (tl + tr) / 2;
    build_tree(v, 2 * pos + 1, tl, mid);
    build_tree(v, 2 * pos + 2, mid + 1, tr);

    seg[pos] = 0;
}

void updateQuery(int pos, int tl, int tr, int l, int r, int add_val)
{
    if (l > r)
    {
        return;
    }

    if (l == tl && r == tr)
    {
        seg[pos] += add_val;
        return;
    }

    int mid = (tl + tr) / 2;
    updateQuery(2 * pos + 1, tl, mid, l, min(mid, r), add_val);
    updateQuery(2 * pos + 2, mid + 1, tr, max(l, mid + 1), r, add_val);
}

int get(int pos, int tl, int tr, int index)
{
    if (tl == tr)
    {
        return seg[pos];
    }

    int mid = (tl + tr) / 2;
    if (index <= mid)
    {
        return seg[pos] + get(2 * pos + 1, tl, mid, index);
    }
    else
    {
        return seg[pos] + get(2 * pos + 2, mid + 1, tr, index);
    }
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
    build_tree(v, 0, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 2)
        {
            int x;
            cin >> x;
            x--;
            cout << get(0, 0, n - 1, x) << endl;
        }
        else
        {
            int a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;

            updateQuery(0, 0, n - 1, a, b, u);
        }
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