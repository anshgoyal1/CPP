#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        while (v[i] % 10 != 0 and v[i] % 10 != 2)
        {
            v[i] += (v[i] % 10);
        }
    }
    set<int> st;
    bool is = false;
    for (auto it : v)
    {
        if (it % 10 == 0)
        {
            is = true;
        }
        st.insert(it);
    }
    // cout << endl;

    if (st.size() == 1)
    {
        cout << "YES" << endl;
        return;
    }
    else if (st.size() >= 2 && is)
    {
        cout << "NO" << endl;
    }
    else
    {
        int val = *st.begin();
        val = val % 20;
        st.erase(st.begin());
        bool ok = true;

        for (auto it : st)
        {
            ok &= (it % 20 == val);
        }

        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
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