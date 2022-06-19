#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {3, 10, 2, 11};
    int n = a.size();

    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
    cout << *max_element(lis,lis + n);
}