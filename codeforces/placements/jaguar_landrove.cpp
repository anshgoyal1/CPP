#include <bits/stdc++.h>
using namespace std;
#define int long long
void largest_number(int n)
{
    string s = to_string(n);

    int max_idx = -1;
    int max_val = -1;
    int left = -1;
    int right = -1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if ((s[i] - '0') > max_val)
        {
            max_idx = i;
            max_val = s[i] - '0';
        }

        if (max_val > (s[i] - '0'))
        {
            left = i;
            right = max_idx;
        }
    }

    swap(s[left], s[right]);
    cout << s << endl;
}
void solve()
{
    int s;
    cin >> s;
    largest_number(s);
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