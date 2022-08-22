// https://discord.com/channels/996058498657960006/998953984821841971/998954722834792569

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    string ans;
    int count = 1;
    int c = 0;
    int cost = 0;
    char prev;
    int mi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (prev == s[i])
        {
            count++;
            c += v[i];
            mi = max(mi, v[i]);
        }
        else
        {
            if (count > 1)
            {
                cost += (c - mi);
            }

            c = v[i];
            count = 1;
            mi = v[i];
        }

        prev = s[i];
    }

    if (s[n - 1] == s[n - 2])
    {
        cost += (c - mi);
    }

    cout << cost << endl;
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