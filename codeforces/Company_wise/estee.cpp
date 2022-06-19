#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> freq(60, 0);

    for (int i = 0; i < n; i++)
    {
        freq[a[i] % 60]++;
    }

    int ans = freq[0] * (freq[0] - 1) / 2;

    for (int i = 1; i <= 30 && (60 - i) != i; i++)
    {
        ans += (freq[i] * freq[60 - i]);
    }

    ans += (freq[60 / 2] * (freq[60 / 2] - 1) / 2);

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