#include <bits/stdc++.h>
using namespace std;

int minCntFrom(int a[], int n)
{
    int dp[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }
    int idxLeft;
    int idxRight;
    for (int i = 0; i < n; i++)
    {
        idxLeft = max(i - a[i], 0);
        idxRight = min(i + a[i] + 1, n);

        dp[idxLeft] = max(dp[idxLeft], idxRight);
    }

    int cntfount = 1;

    idxRight = dp[0];
    int idxNext = -1;

    for (int i = 0; i < n; i++)
    {
        idxNext = max(idxNext, dp[i]);

        if (i == idxRight)
        {
            cntfount++;
            idxRight = idxNext;
        }
    }
    return cntfount;
}

int main()
{
}