#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int x;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        bool temp = binary_search(v.begin(), v.end(), x);
        if (temp)
            yes else no
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