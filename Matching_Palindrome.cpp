#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

bool isPalin(string s)
{
    string k = s;
    reverse(k.begin(), k.end());
    return k == s;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<char> st;
    for (auto it : s)
    {
        st.insert(it);
    }

    if (st.size() == 1)
    {
        cout << s[0] << endl;
    }
    else
    {
        if (n % 2 == 1)
        {
            string x = s;
            string ans;
            for (int i = 0; i < n; i++)
            {
                if (isPalin(s + x))
                {
                    ans = x;
                }
                x = x.substr(1);
            }

            cout << ans << endl;
        }
        else
        {
            string a = s.substr(0, n / 2);
            string b = s;

            if (isPalin(s + a))
            {
                cout << a << endl;
            }
            else
            {
                cout << b << endl;
            }
        }
    }
    // cout << ans << endl;
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}