#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl '\n'

void code_likh_le()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < n; i++)
    {
        ans += '1';
    }
    int cnt = 0;

    for (int i = 0, j = 0; j < n; j++)
    {
        if (s[j] == '1')
        {
            cnt++;
        }

        if (cnt > k)
        {
            while (i < n && (cnt > k || s[i] == '0'))
            {
                if (s[i] == '1')
                {
                    cnt--;
                }
                i++;
            }

            ans = min(ans, s.substr(i, j - i + 2));
        }
    }
    ans = min(ans, s);

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

        code_likh_le();

    return 0;
}