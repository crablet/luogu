// 这一题用到的是唯一分解式
#include <iostream>
#include <cmath>

using ll = long long;

// 算出n里面最大能除掉多少d，返回d的k次方
int DivedeAll(int &n, int d)
{
    int x = 1;
    while (n % d == 0)
    {
        n /= d;
        x *= d;
    }

    return x;
}

ll Solve(int n)
{
    if (n == 1) // 注意特判：1 == 1 * 1
    {
        return 2;
    }

    ll Ans = 0; // 最后的答案
    int pf = 0; // 质因子的个数
    int m = static_cast<int>(std::sqrt(n)); // 不要放在循环里，因为要修改n的值
    for (int i = 2; i <= m; ++i)
    {
        if (n % i == 0) // i是一个新的质因子
        {
            ++pf;
            Ans += DivedeAll(n, i);
        }
    }

    if (n > 1)  // 如果除到最后还有剩余的，那就把它也加上去
    {
        ++pf;
        Ans += n;
    }
    if (pf <= 1)
    {
        ++Ans;  // 如果n这个数是个质数，那还要加上1(n == 1 * n)
    }

    return Ans;
}

int main()
{
    int n, NO = 0;
    while (std::cin >> n && n)
    {
        std::cout << "Case " << ++NO << ": " << Solve(n) << std::endl;
    }

    return 0;
}