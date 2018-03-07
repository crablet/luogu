// 条件概率题：
// 直接打一枪没事的概率是等于子串"00"的个数除以"00"和"01"的个数（即0的个数）
// 这前面的一个0表示上一个人打的是空弹，后面的0/1表示这次的子弹情况
// 转一下再打一枪没事的概率等于0在该字符串中出现的概率
// 以a表示子串"00"的个数，b表示0的个数，n表示字符串长度
// 所以就只要比较a/b和b/n的大小即可
// 然后交叉相乘一下，避免除0的错误，也不用怕精度问题
#include <iostream>
#include <string>

int main()
{
    std::string Str;
    while (std::cin >> Str)
    {
        int a = 0, b = 0;
        auto n = static_cast<int>(Str.size());
        for (int i = 0; i < n; ++i)
        {
            if (Str[i] == '0')
            {
                ++b;    // b表示0的个数
                if (Str[(i + 1) % n] == '0')    // 注意是个环形的，所以要取模
                {
                    ++a;    // a表示"01"串的个数
                }
            }
        }

        if (a * n == b * b)
        {
            std::puts("EQUAL");
        }
        else if (a * n > b * b)
        {
            std::puts("SHOOT");
        }
        else
        {
            std::puts("ROTATE");
        }
    }

    return 0;
}