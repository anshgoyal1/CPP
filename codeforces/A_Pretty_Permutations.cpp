#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);

    if (n % 2 == 1)
    {
        a[n - 2] = n - 1;
        a[n - 1] = n;
        a[n] = n - 2;
        n -= 3;
    }

    for (int i = 1; i <= n; i += 2)
    {
        a[i] = i + 1;
        a[i + 1] = i;
    }

    for (int i = 1; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();

    return 0;
}
