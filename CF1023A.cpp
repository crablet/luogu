// 字符串模拟题
// 首先先特判掉"n > m + 1"的情况，因为第一个字符串都比第二个字符串长，那肯定不行
// 然后特判掉没有'*'的情况，直接两个字符串匹配即可
// 接着找到'*'的位置，以此分割第一个字符串，从前往后和从后往前去匹配第二个字符串
// 一旦出现任何失配，则输出"NO"，否则输出"YES"
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    if (n > m + 1)  // 特判长度
    {
        std::cout << "NO" << std::endl;

        return 0;
    }

    std::string Str1, Str2;
    std::cin >> Str1 >> Str2;

    auto Pos = Str1.find('*');
    if (Pos == std::string::npos)   // 没有'*'的情况
    {
        if (Str1 == Str2)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }
    else
    {
        auto p = static_cast<int>(Pos);
        for (int i = 0; i < p; ++i) // 从前往后扫
        {
            if (Str1[i] != Str2[i])
            {
                std::cout << "NO" << std::endl;

                return 0;
            }
        }
        for (int i = n - 1, j = m - 1; i > p; --i, --j) // 从后往前扫
        {
            if (Str1[i] != Str2[j])
            {
                std::cout << "NO" << std::endl;

                return 0;
            }
        }

        std::cout << "YES" << std::endl;
    }

    return 0;
}