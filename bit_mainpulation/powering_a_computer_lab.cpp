#include <iostream>
using namespace std;

int main()
{
    int T, N, K;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> K;
        int mask = (1 << N) - 1;
        // cout << mask << endl;
        if ((mask & K) == mask)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}