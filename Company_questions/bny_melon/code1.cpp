#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;
    vector<int> x;
    for (int i = 0; i < k; i++)
    {
        x.push_back(v[i]);
    }

    sort(x.begin(), x.end());
    int mx = x[0];
    cout << mx << " ";
    for (int i = k; i < n; i++)
    {
        if (v[i] > mx)
        {
            mx = v[i];
        }

        cout << mx << " ";
    }
    cout << endl;
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