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
    vector<int> pos, neg, a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x > 0)
        {
            pos.push_back(x);
        }
        else if (x < 0)
        {
            neg.push_back(x);
        }
        else
        {
            if (a.size() < 2)
            {
                a.push_back(x);
            }
        }
    }

    if (pos.size() > 2 || neg.size() > 2)
    {
        cout << "NO" << endl;
        return;
    }

    for (auto i : pos)
    {
        a.push_back(i);
    }

    for (auto i : neg)
    {
        a.push_back(i);
    }

    int m = a.size();

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                bool ok = false;

                for (int l = 0; l < m; l++)
                {
                    if (a[i] + a[j] + a[k] == a[l])
                    {
                        ok = true;
                    }
                }

                if (!ok)
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;
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