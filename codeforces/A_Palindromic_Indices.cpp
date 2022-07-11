#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    int idx = n / 2;
    char p = s[idx];
    int c = 1;
    int i = idx - 1;
    while (i >= 0 && s[i] == p)
    {
        c++;
        i--;
    }
    i = idx + 1;
    while (i < n && s[i] == p)
    {
        c++;
        i++;
    }
    cout << c << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)

        solve();

    return 0;
}