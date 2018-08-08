// 思路：先预处理一下每一个数共出现了多少次，然后枚举合法的天数
#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    if (n > m)  // 僧多粥少，明显一天都走不动
    {
        std::cout << 0 << std::endl;
    }
    else if (n == m)    // 刚好相等，一人一口，一天吃完
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::unordered_map<int, int> Map;
        for (int i = 0; i < m; ++i) // 统计每个数各出现了多少次
        {
            int t;
            std::cin >> t;
            ++Map[t];
        }

        for (int k = m / n; k >= 1; --k)    // 枚举合法的天数（k代表天数），最高只能是(m / n)天
        {
            int Tol = 0;
            for (const auto &r : Map)
            {
                Tol += r.second / k;
            }

            if (Tol >= n)   // 一旦遇到一个合法的就退出，因为我们是从高向低枚举的
            {
                std::cout << k << std::endl;

                break;
            }
        }
    }

    return 0;
}