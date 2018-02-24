// 这一题的更详细的解释还是得看紫书P242
// 我这里只是给出其中一种按书上思路的实现并且附上详尽的注释
// 希望能对大家理解这一题有一点点的帮助
#include <iostream>
#include <array>
#include <set>

constexpr int MaxN = 200000 + 5;

int n;
std::array<int, MaxN> a{ 0 }, f{ 0 }, g{ 0 };

struct Pair
{
    int a, g;

    Pair() = default;
    Pair(int a, int g) :
        a(a), g(g)
    {
    }

    // 这是给std::set用的，让其以a的升序来排列
    // 这里用上std::set是利用了其有序的性质
    bool operator<(const Pair &r) const noexcept
    {
        return a < r.a;
    }
};

// 这一题输入量较大，还是最好用上快读
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
    int T;
    T = Read();
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            a[i] = Read();
        }

        // 如果原序列长度为一，那最大递增序列长度也只能是一
        if (n == 1)
        {
            std::puts("1");
            continue;
        }

        // g[i]为以第i个元素结尾的最长L序列长度
        g[0] = 1;
        for (int i = 1; i < n; ++i) // 这个要正着数
        {
            if (a[i - 1] < a[i])    // 如果序列能递增
            {
                g[i] = g[i - 1] + 1;    // 那就是上一个长度再加一，类似于动态规划
            }
            else
            {
                g[i] = 1;   // 否则以它结尾的最大递增序列只能是它自己
            }
        }

        // f[i]为以第i个元素开头的最长L序列长度
        f[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i)    //这个要倒着数
        {
            if (a[i] < a[i + 1])    // 如果序列能递增
            {
                f[i] = f[i + 1] + 1;    // 那就是上一个长度再加一，类似于动态规划
            }
            else
            {
                f[i] = 1;   // 否则以它结尾的最大递增序列只能是它自己
            }
        }

        std::set<Pair> s;
        s.insert(Pair(a[0], g[0]));
        int Ans = 1;    // 最大递增序列至少有一个元素
        for (int i = 1; i < n; ++i) // 对每一组数字枚举
        {
            Pair c(a[i], g[i]);
            auto it = s.lower_bound(c); // 找到首个不小于c的元素的位置
            bool Keep = true;
            if (it != s.begin())    // 确保迭代器自减后不会越界
            {
                auto Last = *(--it);
                auto Len = f[i] + Last.g;   // 以a[j]结尾a[i]开头的递增子序列的长度
                Ans = std::max(Ans, Len);   // 更新答案

                if (c.g <= Last.g)  // 它的潜力不够了，就不应该被保留
                {
                    Keep = false;
                }
            }

            if (Keep)
            {
                s.erase(c);
                s.insert(c);    // 更新一下c的位置

                it = ++s.find(c);
                while (it != s.end() && it->a > c.a && it->g <= c.g)
                {
                    // 删除那些数字比c大的，但能以之结尾的递增序列却比c短的
                    s.erase(it++);
                }
            }
        }

        std::cout << Ans << std::endl;
    }

    return 0;
}