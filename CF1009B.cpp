// 本题就是用的贪心，道理跟楼上几位dalao说的一样，因为'1'可以随意动，所以'1'是一个可以被放到任意地方的字符
// 我们首先对该字符串遍历一遍，这一遍主要统计字符'1'的个数以及该字符串内是否存在'2'
// 然后我们遵循如下的贪心策略：
// 对该字符串进行遍历，遇到'0'就输出'0'，遇到'1'就跳过，直到遇到第一个'2'，我们就将所有的'1'输出，然后再输出一个'2'
// 再接着（先前已经把所有的'1'都输出了），遇到'0'就输出'0'，遇到'1'就跳过，遇到'2'就输出'2'
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string Str;
    std::cin >> Str;

    int One = 0, Zero = 0;
    bool HasTwo = false;
    for (const auto &c : Str)
    {
        if (c == '0')   // 统计'0'的个数
        {
            ++Zero;
        }
        else if (c == '1')   // 统计'1'的个数
        {
            ++One;
        }
        else if (c == '2')  // 统计是否有'2'
        {
            HasTwo = true;
        }
    }

    if (!HasTwo)    // 如果没有'2'，那么就先输出所有的'0'，再输出所有的'1'，然后直接退出程序
    {
        for (int i = 0; i < Zero; ++i)
        {
            std::cout << 0;
        }
        for (int i = 0; i < One; ++i)
        {
            std::cout << 1;
        }
        std::cout << std::endl;

        return 0;
    }

    bool Met = false;   // 标记是否第一次遇见'2'
    for (const auto &c : Str)
    {
        if (c == '0')   // 遇到'0'则输出
        {
            std::cout << 0;
        }
        else if (c == '1')  // 遇到'1'则跳过
        {
            continue;
        }
        else if (c == '2')
        {
            if (!Met)   // 第一次遇到'2'，则输出所有的'1'，再输出一个'2'
            {
                Met = true;

                for (int i = 0; i < One; ++i)
                {
                    std::cout << 1;
                }
                std::cout << 2;
            }
            else       // 不是第一次遇到'2'，则直接输出'2'
            {
                std::cout << 2;
            }
        }
    }
    std::cout << std::endl;

    return 0;
}