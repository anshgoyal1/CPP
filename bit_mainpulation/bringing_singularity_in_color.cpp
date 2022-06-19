#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull get_count(int &n)
{
    ull sum = 0LLU;
    ull step = 1LLU << (n - 1);
    string color;
    while (n--)
    {
        cin >> color;
        if (color == "R")
            sum += step;
        step >>= 1U;
        // cout << step << endl;
    }
    return sum;
}

int main()
{
    int n = 0;
    cin >> n;

    cout << get_count(n);
    return 0;
}