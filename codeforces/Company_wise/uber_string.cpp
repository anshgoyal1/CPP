#include <bits/stdc++.h>
using namespace std;
#define int long long

bool allCharacterMatching(string a, string b)
{
    unordered_set<char> st(a.begin(), a.end());

    for (auto c : b)
    {
        if (st.find(c) == st.end())
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    string a, b;
    cin >> a >> b;

    if (!allCharacterMatching(a, b))
    {
        return;
    }

    unordered_map<char, vector<int>> mp;
    for (int i = 0; i < a.length(); i++)
    {
        mp[a[i]].push_back(i);
    }

    int index = 0;
    int ans = 0;
    int n = b.length();

    while (index < n)
    {
        int aIdx = 0;
        while (index < n)
        {
            char c = b[index++];
            vector<int> v = mp[c];
            auto it = upper_bound(v.begin(), v.end(), aIdx);

            if (it == v.end())
            {
                index--;
                break;
            }
            else
            {
                int pos = *it;
                aIdx = pos;
            }
        }

        if (index < n)
        {
            ans += a.length();
        }
        else
        {
            ans += aIdx + 1;
        }
    }

    cout << ans << endl;
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
