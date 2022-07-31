#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve1()
{
    int n;
    cin >> n;

    string s;
    while (n)
    {
        if (n & 1)
        {
            s += '1';
        }
        else
        {
            s += '0';
        }

        n /= 2;
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            cout << i + 1 << endl;
        }
    }
    cout << s;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        string s = v[i];
        int count = 0;
        char prev;
        for (auto c : s)
        {
            if (c == prev)
            {
                prev = '-';
                count++;
            }
            else
            {
                prev = c;
            }
        }

        ans.push_back(count);
    }
    for (auto it : ans)
    {
        cout << it << " ";
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

        solve1();

    return 0;
}