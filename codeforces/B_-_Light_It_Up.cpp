#include <bits/stdc++.h>
using namespace std;
long long n, m, x[2001], y[2001], a[10000001], u, v, u2, v2, u3, v3;
bool f;
double ans = INT_MAX, ans1 = -INT_MAX;
double jl(double x, double y, double x2, double y2)
{
    return sqrt(abs(x - x2) * abs(x - x2) + abs(y - y2) * abs(y - y2));
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    // printf("%.18lf",ans);
    for (int i = 1; i <= n; i++)
    {
        ans = INT_MAX;
        for (int j = 1; j <= m; j++)
        {
            ans = min(ans, jl(x[i], y[i], x[a[j]], y[a[j]]));
        }
        ans1 = max(ans1, ans);
    }
    printf("%.48lf", ans1);
}
