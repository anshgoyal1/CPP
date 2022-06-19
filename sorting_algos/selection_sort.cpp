#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &a, int n)
{
    int min_index;

    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
}

int main()
{
    vector<int> a = {2, 9, 5, 6, 12, 3};
    selection_sort(a, 6);
    for (auto i : a)
    {
        cout << i << " ";
    }
}