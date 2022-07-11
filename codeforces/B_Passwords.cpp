#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s.length()]++;
    }
    string ans;
    cin >> ans;
    int l = ans.size();
    int c = 0;
    int an = 0;
    for (auto it : m)
    {
        if (it.first == l)
        {
            break;
        }
        c += it.second;
    }
    int min = c + (c / k) * (5) + 1;
    c += m[l];

    int max = c + ((c - 1) / k) * 5;
    cout << min << " " << max << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;

    // while (t--)

    solve();

    return 0;
}