#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin >> s;
    vector<string> v;
    string p = s;
    do
    {
        v.push_back(p);
        next_permutation(p.begin(), p.end());
    } while (p != s);

    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for (auto it : v)
    {
        cout << it << endl;
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