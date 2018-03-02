// 楼上大佬的题解我有点不太理解
// 我发一个跟我一样弱的都能看懂的做法
// 希望能对大家有帮助
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <array>

// 这题数据量还是比较大的，上快读加速明显
int Read()
{
    int n = 0, k = 1;
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
        ch = getchar();

    if (ch == '-')
    {
        k = -1;
        ch = getchar();
    }

    while (ch <= '9' && ch >= '0')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }

    return n * k;
}

int main()
{
    static std::array<int, 100000> Book{ 0 };
    int n, k;
    n = Read();
    k = Read();

    // v：存放答案的左端点和右端点
    // s：可行序列
    // l：左端点
    // r：右端点
    // Ans：最长的序列长度
    std::vector<std::pair<int, int>> v;
    std::multiset<int> s;
    int l = 0, Ans = 0;
    for (int r = 0; r < n; ++r)
    {
        Book[r] = Read();
        s.insert(Book[r]);  // 利用std::multiset有序且可重复的特性
        while (*s.crbegin() - *s.cbegin() > k)
        {
            // 如果最大的减去最小的超范围了，那就不停地删掉左端点
            // 直到满足 <= k 为止
            // 这样做稍微有一点点尺取法的味道
            s.erase(s.find(Book[l]));
            ++l;
        }

        if (r - l + 1 > Ans)    // 如果得到了一个更长的序列，那就更新答案
        {
            v.clear();
            Ans = r - l + 1;
            v.push_back({ l + 1, r + 1 });  // 我从0开始算的，所以要加一
        }
        else if (r - l + 1 == Ans)  // 同样长的也要
        {
            v.push_back({ l + 1, r + 1 });
        }
    }

    std::cout << Ans << ' ' << v.size() << std::endl;
    for (const auto &r : v)
    {
        std::cout << r.first << ' ' << r.second << std::endl;
    }

    return 0;
}