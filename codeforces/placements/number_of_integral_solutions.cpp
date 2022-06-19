#include <bits/stdc++.h>
using namespace std;

int getSum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i <= 81; i++)
    {
        int x = pow(i, a);

        int p = b * x + c;

        if (getSum(p) == i)
        {
            cout << p << endl;
        }
    }
}