#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }

    cout << n << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }

        cout << endl;
        swap(v[i], v[i + 1]);
    }
    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;
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