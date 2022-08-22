#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define v2i vector<vi>
#define ii pair<int, int>
#define F first
#define S second
#define all(X) (X).begin(), (X).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

const int N = 1e2 + 5, MX = 1e5;
int tc = 1, n, dp[N], tl;
string t;
vector<string> a;

int f(int idx)
{
    if (idx == tl)
        return dp[idx] = 0;
    if (dp[idx] != MX)
        return dp[idx];

    int ops = MX;

    for (int i = 0; i < n; i++)
        if (idx + a[i].length() - 1 < tl && t.substr(idx, a[i].length()) == a[i])
            for (int k = 1; k <= a[i].length(); k++)
            {
                ops = min(ops, 1 + f(idx + k));
            }

    return dp[idx] = ops;
}

signed main()
{
    fastio;
    cin >> tc;
    while (tc--)
    {
        fill(dp, dp + N, MX);

        cin >> t >> n;
        tl = t.length();

        a.resize(n);
        for (string &s : a)
            cin >> s;

        int res = f(0);
        if (res == MX)
            cout << -1 << '\n';
        else
        {
            cout << res << '\n';
            vector<ii> path;

            int current_ops = res;

            int idx = 0;

            while (idx < tl)
            {
                for (int i = 0; i < n; i++)
                {
                    bool moved = false;
                    if (idx + a[i].length() - 1 < tl && t.substr(idx, a[i].length()) == a[i])
                        for (int k = 1; k <= a[i].length(); k++)
                        {
                            if (dp[idx] == 1 + dp[idx + k])
                            {
                                moved = true;
                                idx = idx + k;
                                path.push_back({i, idx - k});
                            }

                            if (moved)
                                break;
                        }

                    if (moved)
                        break;
                }
            }

            for (auto x : path)
                cout << x.F + 1 << ' ' << x.S + 1 << '\n';
        }
    }

    return 0;
}