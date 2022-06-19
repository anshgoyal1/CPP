#include <bits/stdc++.h>
using namespace std;
#define int long long
int primes[1000006];
void preprocess()
{

    // Initialize all the positions
    // with their respective values
    for (int i = 1; i <= 1000000; i++)
        primes[i] = i;

    // Iterate over the range [2, sqrt(10^6)]
    for (int i = 2; i * i <= 1000000; i++)
    {

        // If i is prime number
        if (primes[i] == i)
        {

            // Mark it as the factor
            for (int j = 2 * i; j <= 1000000; j += i)
            {
                if (primes[j] == j)
                    primes[j] = i;
            }
        }
    }
}

int steps(int x, int m)
{
    int st = 0;
    bool flag = false;

    while (x > 1)
    {
        if (primes[x] > m)
        {
            flag = true;
            break;
        }

        x /= primes[x];
        st++;
    }

    if (flag == true)
    {
        return -1;
    }

    return st;
}

void minimumSteps(int x, int y, int m)
{
    preprocess();

    int k = __gcd(x, y);
    x /= k;
    y /= k;

    int x_steps = steps(x, m);
    int y_steps = steps(y, m);

    if (x_steps == -1 || y_steps == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << x_steps << " " << y_steps << endl;
    }
}

void topoogicalSortUtil(vector<vector<int>> adj, int u, vector<bool> &vis, stack<int> &st)
{
    vis[u] = true;

    for (auto it : adj[u])
    {
        if (!vis[it])
        {
            topoogicalSortUtil(adj, it, vis, st);
        }
    }

    st.push(u);
}

void shortestPath(vector<vector<int>> adj, int n)
{
    vector<bool> vis(n + 1, false);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topoogicalSortUtil(adj, i, vis, st);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

void smallest_subarray_with_given_sum(vector<int> &a, int sum)
{
    int curr_sum = 0;
    int min_len = a.size() + 1;
    int start = 0;
    int end = 0;
    int n = a.size();
    while (end < n)
    {
        while (curr_sum <= sum && end < n)
        {
            curr_sum += a[end++];
        }

        while (curr_sum > sum && start < end)
        {
            min_len = min(min_len, end - start);
            curr_sum -= a[start++];
        }
    }
}

int min_swaps(string s, int k)
{
    int n = s.size();
    string k = s;
    for (int i = 0; i < k; i++)
    {
        next_permutation(s.begin(), s.end());
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != k[i])
        {
            int start = i + 1;

            while (k[i] != s[start])
            {
                start++;
            }

            while (i != start)
            {
                swap(k[i], s[start]);
                start--;
                ans++;
            }
        }
    }
    return ans;
}

bool isPrime(int x)
{
    if (x <= 1)
        return false;

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)

            // Return not prime
            return false;
    }

    // If prime return true
    return true;
}

void largest_prime(string s)
{
    vector<pair<string, int>> v = {"", 0};

    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int n = v.size();

        for (int j = 0; j < n; j++)
        {
            pair<string, int> p = v[j];

            string str = p.first;
            int val = p.second;

            if (s[i] == '1')
            {
                temp.first = str + '1';

                val = ((val << 1) + 1);
            }
            else
            {
                temp.first = str + '0';

                val = ((val << 1) + 0);
            }

            v.push_back(temp);

            int check = temp.second;

            if (isPrime(check))
            {
                ans = max(ans, check);
            }
        }
    }
    cout << ans << endl;
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