// 这一题十分暴力，就是枚举
#include <iostream>
#include <array>

constexpr int MaxN = 100 * 2 + 5;
constexpr int M = 10001;

int T;
std::array<int, MaxN> x{ 0 };

void Solve()
{
    for (int a = 0; a < M; ++a) // 枚举a
    {
        for (int b = 0; b < M; ++b) // 枚举b
        {
            bool OK = true;
            for (int i = 2; i <= T * 2; i += 2)
            {
                x[i] = (a * x[i - 1] + b) % M;
                // 如果这个a和b能使数列满足递推关系，那就一直递推下去
                // 否则就重新来过，继续试验
                if (i + 1 <= T * 2 && x[i + 1] != (a * x[i] + b) % M)
                {
                    OK = false;
                    break;
                }
            }

            if (OK) // 如果找到其中一组a和b了，依题意，那就退出
            {
                return;
            }
        }
    }
}

int main()
{
    while (std::cin >> T)
    {
        for (int i = 1; i <= T * 2 - 1; i += 2) // 读入奇数项的
        {
            std::cin >> x[i];
        }
        Solve();
        for (int i = 2; i <= T * 2; i += 2) // 输出偶数项的
        {
            std::cout << x[i] << std::endl;
        }
    }

    return 0;
}