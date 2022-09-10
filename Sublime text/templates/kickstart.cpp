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
    ll n, k;
    cin >> n >> k;
    vi v(n);
    unordered_map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second > 2)
        {
            cout << "NO" << endl;
            return;
        }
    }

    if (n > 2 * k)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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