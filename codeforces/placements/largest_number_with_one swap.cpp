#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int max_digit = -1;
    int max_idx = -1;
    int left = -1;
    int right = -1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (max_digit < (s[i] - '0'))
        {
            max_digit = (s[i] - '0');
            max_idx = i;
        }

        if (max_digit > (s[i] - '0'))
        {
            left = i;
            right = max_idx;
        }
    }
    if (left == -1)
    {
        cout << s << endl;
        return 0;
    }
    swap(s[left], s[right]);

    cout << s << endl;
    return 0;
}