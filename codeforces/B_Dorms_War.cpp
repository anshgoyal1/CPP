#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<char> st;
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        char p;
        cin >> p;
        st.insert(p);
    }
    string k;
    for (auto it : s)
    {
        if (st.find(it) != st.end())
        {
            k += '1';
        }
        else
        {
            k += '0';
        }
    }
    int ma = 0;
    for (int i = n - 1; i >= 0; i--)
    {

        if (k[i] == '1')
        {
            int j = i - 1;
            int l = 0;

            while (k[j] == '0' && j >= 0)
            {
                l++;
                j--;
            }

            if (j != -1)
            {
                l++;
            }
            i = j + 1;
            ma = max(ma, l);
        }
    }
    cout << ma << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}