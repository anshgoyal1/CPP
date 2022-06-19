#include <iostream>
#include <queue>
using namespace std;

string get_string(string S)
{
    string result = "";
    int len = S.length(), i;
    deque<char> dq;

    for (i = 0; i < len; i++)
    {
        if (S[i] != '@')
            dq.push_back(S[i]);
        else
        {
            // frequency represents the count of consecutive '@'s
            int frequency = 0;
            while (i < len && S[i] == '@')
            {
                frequency++;
                i++;
            }

            // stores updated popped characters
            string temp = "";
            while (!dq.empty() && frequency--)
            {
                char ch = dq.back();
                dq.pop_back();
                temp += toupper(ch);
            }

            // pushing updated characters back into deque
            for (int j = temp.length() - 1; j >= 0; j--)
                dq.push_back(temp[j]);

            // because i is already incremented in the while loop above
            i -= 1;
        }
    }

    while (!dq.empty())
    {
        result += dq.front();
        dq.pop_front();
    }

    return result;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        cout << get_string(S) << endl;
    }

    return 0;
}
