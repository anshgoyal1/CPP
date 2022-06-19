#include <bits/stdc++.h>
using namespace std;
#define int long long

class Solution
{
public:
    int dp[500001][3];
    int solve(vector<int> &a, int i, int l)
    {
        if (i == a.size() - 1)
        {
            return 0;
        }

        if (l + 1 == a[i])
        {
            return 1e9;
        }

        if (dp[i][l] != -1)
        {
            return dp[i][l];
        }

        if (a[i + 1] != l + 1)
        {
            return dp[i][l] = solve(a, i + 1, l);
        }
        else
        {
            return dp[i][l] = 1 + min(solve(a, i, (l + 1) % 3), solve(a, i, (l + 2) % 3));
        }
    }
    int minSideJumps(vector<int> &obstacles)
    {
        memset(dp, -1, sizeof(dp));
        return solve(obstacles, 0, 1);
    }
};

int solution(vector<int> A, int S, int K)
{
    int n = A.size();
    // two max heaps
    priority_queue<vector<int>> p, q;
    // two pointers
    int l = 0, r = n - 1;
    int ans = 0;

    // storing negative index because it will prioritize lower index first if elements.first are same in max heap
    for (int i = 0; i < K; i++)
    {
        p.push({A[l], -l});
        l++;
        q.push({A[r], -r});
        r--;
    }

    while (S--)
    {
        int ptop = p.top()[0];
        int qtop = q.top()[0];
        int pid = p.top()[1];
        int qid = q.top()[1];

        if (ptop > qtop || (ptop == qtop && -pid < -qid))
        {
            ans += ptop;
            p.pop();
            p.push({A[l], -l});
            l++;
        }
        else
        {
            ans += qtop;
            q.pop();
            q.push({A[r], -r});
            r--;
        }
    }
    return ans;
}

void solve()
{
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)

        solve();

    return 0;
}