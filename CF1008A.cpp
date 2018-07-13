// 来自yyf的一句话题意：判断一个字符串是不是除了'n'这个辅音后面总是跟着一个元音字母
#include <iostream>
#include <string>

bool OK(char c) // 判断字母c是否为元音字母
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string Str;
    std::cin >> Str;

    // 继续默读来自yyf的一句话题意：判断一个字符串是不是除了'n'这个辅音后面总是跟着一个元音字母
    for (std::size_t i = 0; i < Str.size(); ++i)
    {
        if (OK(Str[i])) // 如果是元音字母，则不考虑
        {
            continue;
        }
        else if (Str[i] == 'n') // 如果是辅音字母但是是'n'，则不考虑
        {
            continue;
        }
        else if (i != Str.size() - 1 && OK(Str[i + 1])) // 否则需要在辅音后面跟一个元音字母
        {
            continue;
        }
        else   // 都不符合前面的条件则说明不是Berlanese
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;

    return 0;
}