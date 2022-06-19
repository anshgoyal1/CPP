// Solution by Tima
#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
#define all(x) x.begin(), x.end()

using namespace std;
const int N = int(3e5) + 12, mod = int(1e9) + 7;

ll x;
ull mx;
int n;
map<ull, int> ma;

int calc(ull x)
{
    if (x >= mx)
        return 0;
    if (ma.count(x))
        return ma[x];
    ull b = x;
    bool ok[12];
    memset(ok, 0, sizeof(ok));
    while (b > 0)
    {
        ok[b % 10] = 1;
        b /= 10;
    }
    int res = mod;
    for (int i = 2; i <= 9; i++)
    {
        if (ok[i])
            res = min(res, calc(x * i) + 1);
    }
    // cerr << x << " " << res << endl;
    return ma[x] = res;
}

void solve()
{
    cin >> n >> x;
    mx = 1;
    for (int i = 1; i < n; i++)
        mx *= 10;
    int res = calc(x);
    if (res >= mod)
        res = -1;
    cout << res;
}

int main()
{
    int T = 1;
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    // cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}