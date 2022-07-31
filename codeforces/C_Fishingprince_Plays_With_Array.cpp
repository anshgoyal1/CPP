#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

vector<pair<int, int>> sol(vector<int> &a, int n, int m)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int ele = a[i];
        int c = 1;

        while (ele % m == 0)
        {
            c *= m;
            ele /= m;
        }

        if (!v.empty() && v.back().first == ele)
        {
            c += v.back().second;
            v.pop_back();
        }

        v.push_back({ele, c});
    }

    return v;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    // int sum1 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // sum1 += a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k);
    // int sum2 = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
        // sum2 += b[i];
    }

    vector<pair<int, int>> v1 = sol(a, n, m);
    vector<pair<int, int>> v2 = sol(b, k, m);

    if (v1 != v2)
    {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    return;
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