#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void solve(string s, string output)
{
    if (s.empty())
    {
        ans.push_back(output);
        return;
    }

    solve(s.substr(1), output + s[0]);

    solve(s.substr(1), output);
}

int main()
{
    string s;
    cin >> s;

    solve(s, "");
    for (auto it : ans)
    {
        cout << it << " ";
    }
}