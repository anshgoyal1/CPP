#include <bits/stdc++.h>

template <typename T>
class fenwick
{
public:
    std::vector<T> fenw;
    int n;
    fenwick(int _n) : n(_n)
    {
        fenw.resize(n);
    }
    void modify(int x, T v)
    {
        while (x < n)
        {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    T get(int x)
    {
        T v{};
        while (x >= 0)
        {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int TestCases;
    std::cin >> TestCases;

    for (int test = 0; test < TestCases; test++)
    {
        int N;
        std::cin >> N;

        fenwick<int> BIT(N + 69);
        std::vector<std::array<int, 2>> Votes;
        for (int i = 0; i < N; i++)
        {
            int x, y;
            std::cin >> x >> y;
            Votes.push_back({x, y});
        }

        for (auto [left, right] : Votes)
        {
            BIT.modify(left, 1);
            BIT.modify(right + 1, -1);
        }

        std::vector<int> ANS;
        for (int i = 0; i < N; i++)
        {
            BIT.modify(Votes[i][0], -1);
            BIT.modify(Votes[i][1] + 1, 1);

            BIT.modify(Votes[i][0], -1);
            BIT.modify(Votes[i][1] + 1, 1);

            if (BIT.get(i + 1) == N - 1)
            {
                ANS.push_back(i);
            }

            BIT.modify(Votes[i][0], 1);
            BIT.modify(Votes[i][1] + 1, -1);

            BIT.modify(Votes[i][0], 1);
            BIT.modify(Votes[i][1] + 1, -1);
        }

        std::cout << (int)ANS.size() << '\n';
        for (int i = 0; i < ANS.size(); i++)
        {
            std::cout << ANS[i] + 1 << '\n';
        }
    }
    return 0;
}