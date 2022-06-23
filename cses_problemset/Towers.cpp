#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> towers;
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(towers.begin(), towers.end(), a[i]);
        if (it == towers.end())
        {
            towers.push_back(a[i]);
        }
        else
        {
            int index = it - towers.begin();
            towers[index] = a[i];
        }
    }

    cout << towers.size() << endl;
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