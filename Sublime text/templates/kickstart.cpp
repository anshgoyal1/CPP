#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define sv(v) sort(v.begin(), v.end())
#define rsv(v) sort(v.rbegin(), v.rend())
#define pb push_back
#define ff first
#define ss second
#define acc(v) accumulate(v.begin(), v.end(), 0LL)
const int N = 1e9 + 7;

bool powerof2(ll n)
{
    return (n && !(n & (n - 1)));
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    rsv(a);
    int j = 0;
    double ans = 0.0;
    for (int i = 0; i < m - 1; i++)
    {
        ans += a[j++];
    }

    vi arr;
    for (int i = j; i < n; i++)
    {
        arr.push_back(a[i]);
    }
    int sz = arr.size();

    if (sz & 1)
    {
        double med = (double)arr[sz / 2];
        ans += med;
    }
    else
    {
        double med = (double)(arr[sz / 2] + arr[(sz - 1) / 2]) / 2;
        ans += med;
    }

    cout << ans << endl;
}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}