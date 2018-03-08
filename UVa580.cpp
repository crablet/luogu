// 用：总组合数 - 安全组合 = 危险组合
// d[i]表示第i个位置以L结束的序列，但前三个要特别说明
// 因此有d[i] = d[i - 1] + d[i - 2] + d[i - 3]
// 然后总的组合数为2^n
// 最后相减即可
#include <iostream>
#include <array>

int main()
{
    std::array<int, 55> d{ 0 };
    d[1] = 2;   // U L
    d[2] = 4;   // UU LL UL LU
    d[3] = 7;   // LLU UUL ULL LLL LUU LUL ULU
    for (int i = 4; i < 55; ++i)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    int n;
    while (std::cin >> n && n)
    {
        std::cout << (1 << n) - d[n] << std::endl;
    }

    return 0;
}