// 这题就是校门外的树，直接模拟即可
#include <iostream>
#include <array>

int main()
{
    constexpr int MaxN = 100 + 10;
    std::array<bool, MaxN> s{ false };  // s[i]表示i这个点是否被覆盖

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    while (n--)
    {
        int l, r;   // 左端点和右端点
        std::cin >> l >> r;
        for (int i = l; i <= r; ++i)
        {
            s[i] = true;    // 直接枚举整个区间里的点
        }
    }

    int Tol = 0;    // 还剩多少个点没被覆盖
    for (int i = 1; i <= m; ++i)
    {
        if (!s[i])
        {
            ++Tol;
        }
    }
    std::cout << Tol << std::endl;

    for (int i = 1; i <= m; ++i)
    {
        if (!s[i])
        {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}