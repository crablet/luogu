// 多拿几个串试一遍就知道，最后状态必然形如：bbb...bbaa...a
// 我们逆序处理该字符串，如果遇到一个'a'，那么就看一下它之前有几个'b'，答案就加上几个，同时'b'的数量要翻倍
// 如果遇到一个'b'，那么'b'的数量就加一，同时答案保持不变
// 因为与'a'直接相邻的'b'的数量则是要被替换成"bba"的次数，然后每次做完这些替换之后'b'的个数会翻倍
// 最后，要注意取模
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    constexpr int MOD = 1000000000 + 7;

    int Ans = 0, b = 0;

    std::string Str;
    std::cin >> Str;
    for (auto Iter = Str.crbegin(); Iter != Str.crend(); ++Iter)
    {
        if (*Iter == 'a')
        {
            Ans = (Ans + b) % MOD;
            b = b * 2 % MOD;
        }
        else if (*Iter == 'b')
        {
            ++b;
        }
    }
    std::cout << Ans << std::endl;

    return 0;
}