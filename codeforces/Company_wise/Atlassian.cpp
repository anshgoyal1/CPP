#include <bits/stdc++.h>
using namespace std;

int squared_dist(pair<int, int> a, pair<int, int> b)
{
    int x = (pow(a.first - b.first, 2) +
             pow(a.second - b.second, 2));
    return x;
}

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    vector<int> y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({x[i], y[i]});
    }

    sort(v.begin(), v.end());
    int dist = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        dist = min(dist, squared_dist(v[i], v[i + 1]));
    }

    cout << dist << endl;
}
