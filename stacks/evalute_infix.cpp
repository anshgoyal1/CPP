#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

int apply(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

void evaluate(string infix)
{
    int i;
    stack<int> num;
    stack<char> st;

    for (i = 0; i < infix.length(); i++)
    {
        if (infix[i] == ' ')
        {
            continue;
        }

        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (isdigit(infix[i]))
        {
            int val = 0;

            while (i < infix.length() && isdigit(infix[i]))
            {
                val = val * 10 + (infix[i] - '0');
                i++;
            }
            num.push(val);
            i--;
        }
        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                int val2 = num.top();
                num.pop();

                int val1 = num.top();
                num.pop();

                char op = st.top();
                st.pop();

                num.push(apply(val1, val2, op));
            }

            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(infix[i]))
            {
                int val2 = num.top();
                num.pop();

                int val1 = num.top();
                num.pop();

                char op = st.top();
                st.pop();

                num.push(apply(val1, val2, op));
            }

            st.push(infix[i]);
        }
    }

    while (!st.empty())
    {
        int val2 = num.top();
        num.pop();

        int val1 = num.top();
        num.pop();

        char op = st.top();
        st.pop();

        num.push(apply(val1, val2, op));
    }

    cout << num.top() << endl;
}
int main()
{
    evaluate("10 + 2 * 6");
}