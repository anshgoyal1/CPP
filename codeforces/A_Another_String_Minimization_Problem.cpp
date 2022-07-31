#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    string s = "";
    for (int i = 0; i < m; i++)
    {
        s += "B";
    }

    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        int y = m + 1 - v[i];
        if (s[x - 1] == 'B' && s[y - 1] == 'B')
        {
            s[min(x - 1, y - 1)] = 'A';
        }
        else if (s[x - 1] == 'B')
        {
            s[x - 1] = 'A';
        }
        else
        {
            s[y - 1] = 'A';
        }
    }

    cout << s << endl;
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