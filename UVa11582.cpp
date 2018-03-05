// 一道数论题：
// 会发现整个数列取模之后有循环节
// 于是我们通过找到那个循环节来简化运算
// 然后熟悉一下“幂取模”的模板还有模运算的一些基本性质
// 具体见代码和注释
#include <iostream>
#include <array>

using ULL = unsigned long long;

constexpr int MaxN = 1000 + 5;

std::array<std::array<ULL, MaxN * 6>, MaxN> f{ 0 };
std::array<ULL, MaxN> Period{ 0 };

int PowMod(ULL a, ULL b, int n) // “幂取模”的模板，算出a^b % n的值
{
    if (!b)
    {
        return 1;
    }

    int k = PowMod(a, b / 2, n);
    k = k * k % n;

    if (b % 2)
    {
        k = k * a % n;
    }

    return k;
}

ULL Solve(ULL a, ULL b, int n)
{
    if (a == 0 || n == 1)
    {
        return 0;
    }

    // 利用公式：a^b % p = ((a % p)^b) % p 
    // 这个公式可以用二项式定理展开验证
    auto p = PowMod(a % Period[n], b, Period[n]);

    return f[n][p];
}

int main()
{
    for (int n = 2; n <= 1000; ++n) // 事先处理好各种n的情况，之后查表即可
    {
        f[n][0] = 0;
        f[n][1] = 1;
        for (int i = 2; ; ++i)
        {
            f[n][i] = (f[n][i - 1] + f[n][i - 2]) % n;  // 用斐波那契数列的模递推
            if (f[n][i - 1] == 0 && f[n][i] == 1)   // 如果出现循环了
            {
                Period[n] = i - 1;  // Period[n]表示当输入n时，第几项出现循环
                break;
            }
        }
    }

    ULL a, b;
    int n, T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> a >> b >> n;
        std::cout << Solve(a, b, n) << std::endl;
    }

    return 0;
}