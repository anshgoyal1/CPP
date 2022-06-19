#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int j = n - 1;
    int k = n - 1;

    while (j > 0 && v[j - 1] >= v[j])
    {
        j--;
    }

    for (int i = j; i < k; i++, k--)
    {
        swap(v[i], v[k]);
    }

    if (j > 0)
    {
        k = j--;

        while (v[j] >= v[k])
        {
            k++;
        }
        swap(v[k], v[j]);
    }
}