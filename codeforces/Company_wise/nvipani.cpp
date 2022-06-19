#include <bits/stdc++.h>
using namespace std;
#define int long long

void tripletsFormingAp(vector<int> a, int n)
{
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = a[j] - a[i];

            if (st.find(a[i] - diff) != st.end())
            {
                cout << a[i] - diff << " " << a[i] << " " << a[i] + diff << endl;
            }
        }
        st.insert(a[i]);
    }
}

int countSubArrayProductLessThanK(vector<int> &c, long long k)
{
    int n = c.size();
    int p = 1;
    int res = 0;

    for (int start = 0, end = 0; end < n; end++)
    {
        p *= c[end];

        while (start < end && p >= k)
        {
            p /= c[start];
            start++;
        }

        if (p < k)
        {
            res += end - start + 1;
        }
    }
    cout << res << endl;
}

void solve()
{
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)

        solve();

    return 0;
}