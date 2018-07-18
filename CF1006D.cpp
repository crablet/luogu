// 这一题要求对字符串a（第一个字符串）进行修改（注意看题，我在这里WA了几遍）
// 于是我们将a、b字符串中的每个字符分组，一头一尾分为一组
// 具体说来就是将{a(i), a(l - i - 1), b(i), b(l - i - 1)}合并成一组
// 然后统计每一组中不同的字符的个数，通过对不同字符个数进行分类讨论得出答案
#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int l;
    std::cin >> l;

    std::string Str1, Str2;
    std::cin >> Str1 >> Str2;

    int Ans = 0;
    for (int i = 0; i < l / 2; ++i)
    {
        std::unordered_map<char, int> Map;
        ++Map[Str1[i]];
        ++Map[Str2[i]];
        ++Map[Str1[l - i - 1]];
        ++Map[Str2[l - i - 1]];

        if (Map.size() == 2)    // 如果只有两个字符不同
        {
            if (Map[Str1[i]] != 2)  // 那就看看其中一个字符的个数是不是2，如果不是的话，证明一个字符是3，一个字符是1，则需要调整一个字符
            {
                ++Ans;
            }
        }
        else if (Map.size() == 3)   // 如果有三个字符不同
        {
            if (Str1[i] == Str1[l - i - 1]) // 看看a字符串头尾是否相等，是的话那么b字符串的头尾都得修改，就是2
            {
                Ans += 2;
            }
            else   // 如果a字符串头尾不相等，那么b字符串只需要修改一个字符即可
            {
                ++Ans;
            }
        }
        else if (Map.size() == 4)   // 如果四个字符都不想等，那就调两个字符出来修改，改成中心对称的形式
        {
            Ans += 2;
        }
    }

    if (l & 1)  // 如果字符串的长度是奇数，那么中间的一对字符需要特殊地拿出来看一下，因为组不成四个字符一组了
    {
        if (Str1[l / 2] != Str2[l / 2]) // 不相等，还得再调整一个字符
        {
            ++Ans;
        }
    }

    std::cout << Ans << std::endl;

    return 0;
}