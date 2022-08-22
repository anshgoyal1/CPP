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
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (mp[v[i]] > 1)
        {
            mp[v[i]]--;
            idx = i;
        }
    }

    if (idx == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << idx + 1 << endl;
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