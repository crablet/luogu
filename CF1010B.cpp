// 先求出整个p序列，再二分
#include <iostream>
#include <array>

int Ask(int p)
{
    std::cout << p << std::endl;
    std::fflush(stdout);

    int t;
    std::cin >> t;
    return t;
}

int main()
{
    constexpr int MaxN = 30 + 5;
    std::array<bool, MaxN> p{ false };

    int m, n;
    std::cin >> m >> n;
    for (int i = 1; i <= n; ++i)    // 先询问n遍1，把p序列求出来，
    {                               // 因为1是最短的距离，所以不可能有-1出现，如果出现了-1，则证明这次是假的答案
        std::cout << 1 << std::endl;
        std::fflush(stdout);

        int t;
        std::cin >> t;
        if (t == -1)    // 出现了-1，则证明是假的答案
        {
            p[i] = false;
        }
        else if (t == 1)    // 返回1才对
        {
            p[i] = true;
        }
        else // 恰好1就是答案
        {
            return 0;
        }
    }

    int l = 2, r = m, Now = 1;
    while (l <= r)
    {
        auto m = (l + r) / 2;
        auto Ans = Ask(m);
        if (p[(Now - 1) % n + 1] == false)  // 如果这次火箭会返回假的答案，我们就给它取个反
        {
            Ans = -Ans;
        }
        if (Ans == 0)
        {
            return 0;
        }
        else if (Ans < 0)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }

        ++Now;
    }

    return 0;
}