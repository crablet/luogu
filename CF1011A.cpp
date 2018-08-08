// 贪心题，首先将字符串按从小到大排序，然后从前往后取字符，只要不是连续的字符就可以取
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::string Str;
    std::cin >> Str;

    std::sort(Str.begin(), Str.end());

    int Ans = Str[0] - 'a' + 1; // 头字符肯定可以取，先取一个看看
    --k;

    if (k == 0)
    {
        std::cout << Ans << std::endl;
    }
    else
    {
        auto Pre = Str[0];  // 记录上一次取得的字符
        for (int i = 1; i < n; ++i)
        {
            if (Str[i] - Pre > 1)   // 不连续则可以取
            {
                Ans += Str[i] - 'a' + 1;
                Pre = Str[i];

                if (--k == 0)
                {
                    std::cout << Ans << std::endl;

                    return 0;
                }
            }
        }

        std::cout << -1 << std::endl;
    }

    return 0;
}