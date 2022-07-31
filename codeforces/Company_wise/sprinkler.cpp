#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> data[1000];

int fun(vector<int> &v)
{
    sort(v.begin(), v.end());

    long sum = 0;
    long ans = 0;

    for (int idx = 1, i = 0, j = v.length() - 1; idx < v.length() + 1; idx++)
    {
        if (idx % 2 == 0)
        {
            sum += v[j--] - v[i++];
        }
        ans += sum;
        data[idx] = sum;
    }
}

int query(int q)
{
    return data[q];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
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

        solve();

    return 0;
}