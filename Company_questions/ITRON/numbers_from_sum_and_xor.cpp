#include <bits/stdc++.h>
using namespace std;
#define int long long
void compute(unsigned long int s, unsigned long int x)
{
    unsigned long int A = s - x;

    int a = 0;
    int b = 0;

    for (int i = 0; i < 8 * sizeof(s); i++)
    {
        unsigned long int Xi = (x & (1 << i));
        unsigned long int Ai = (A & (1 << i));

        if (Xi == 0 && Ai == 0)
        {
        }
        else if (Xi == 0 && Ai > 0)
        {
            a = ((1 << i) | a);
            b = ((1 << i) | b);
        }
        else if (Xi > 0 && Ai == 0)
        {
            a = ((1 << i) | a);

            // We leave i-th bit of b as 0.
        }
        else // (Xi == 1 && Ai == 1)
        {
            cout << "Not Possible";
            return;
        }
    }
}
void solve()
{
    int s, x;
    cin >> s >> x;

    for (int i = 1; i < s; i++)
    {
        int a = i;
        int b = s - i;
        if (a ^ b == x)
        {
            cout << a << " " << b << endl;
            return;
        }
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