// 思路：
// 由于数据有些大，所以先对该“字符串”进行离散化
// 然后套用莫队，求出区间众数即可
#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>

constexpr int MaxN = 400000 + 5;
std::array<int, MaxN> s{ 0 }, q{ 0 }, d{ 0 }, Ans{ 0 }, Sum{ 0 }, cnt{ 0 };
// Sum[t]表示t这个数出现的次数
// cnt[i]表示出现了i次的数有几个
// Ans[i]表示第i次的询问的答案

int Read()
{
    int n = 0, k = 1;
    char ch = std::getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = std::getchar();
    }

    if (ch == '-')
    {
        k = -1;
        ch = std::getchar();
    }

    while (ch <= '9' && ch >= '0')
    {
        n = n * 10 + ch - '0';
        ch = std::getchar();
    }

    return n * k;
}

class Query
{
public:
    int x, y, id;

    Query() = default;
    Query(int x, int y, int id) :
        x(x), y(y), id(id)
    {
    }

    bool operator<(const Query &rhs) const noexcept
    {
        if (s[x] != s[rhs.x])   // 如果处于不同的分块，那就按分块的次序来排列
        {
            return s[x] < s[rhs.x];
        }
        else // 如果处于相同的分块，那就按照右端点的次序来排列
        {
            return y < rhs.y;
        }
    }
};

std::array<Query, MaxN> Que;

int main()
{
    int n, m;
    n = Read();
    m = Read();

    int sqt = static_cast<int>(std::sqrt(n));
    for (int i = 1; i <= n; ++i)
    {
        int t;
        t = Read();
        q[i] = t;   // 将要被排序去重的数组
        d[i] = t;   // 原数组，记录下原封不动的数字序列，就是题目中的“字符串”
        s[i] = i / sqt;   // 分块
    }

    // 先给q数组排序，然后求出不相同的元素的个数（Size），为后面离散化做准备
    std::sort(q.begin() + 1, q.begin() + n + 1);
    auto Size = std::unique(q.begin() + 1, q.begin() + n + 1) - (q.begin() + 1);
    for (int i = 1; i <= n; ++i)
    {
        // 记录下原数组中每个数是第几大的，也就是离散化了
        d[i] = std::lower_bound(q.begin() + 1, q.begin() + Size + 1, d[i]) - q.begin();
    }
    for (int i = 1; i <= m; ++i)
    {
        int l, r;
        l = Read();
        r = Read();
        Que[i] = std::move(Query(l, r, i));
    }
    std::sort(Que.begin() + 1, Que.begin() + m + 1);    // 用莫队前要先排序

                                                        // 注意l一定要从1开始，我在这里WA了四次!
    int l = 1, r = 0, Now = 1;
    cnt[0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        auto x = Que[i].x, y = Que[i].y;

        while (l > x)   // 当前l在询问的左端点的右侧
        {
            --l;    // l退一步
            auto &t = Sum[d[l]];    // t：数字d[l]出现的个数
            --cnt[t];   // 数字d[l]的个数发生了变化，这一句有点绕
            if (Now == t)   // 如果遇到了原来的众数，就把计数器加一
            {
                ++Now;
            }

            ++t;    // 这时候才可以更新数字d[l]的个数
            ++cnt[t];
        }

        // 后面的也还是莫队的套路，同理了
        while (r < y)
        {
            ++r;
            auto &t = Sum[d[r]];
            if (Now == t)
            {
                ++Now;
            }

            --cnt[t];
            ++t;
            ++cnt[t];
        }

        while (l < x)
        {
            auto &t = Sum[d[l]];
            --cnt[t];
            if (Now == t && cnt[t] == 0)    // 如果没有别的数也能有那么多个，那计数器就得减一了
            {
                --Now;
            }

            --t;
            ++cnt[t];
            ++l;
        }

        while (r > y)
        {
            auto &t = Sum[d[r]];
            --cnt[t];
            if (Now == t && cnt[t] == 0)
            {
                --Now;
            }

            --t;
            ++cnt[t];
            --r;
        }

        Ans[Que[i].id] = Now;
    }

    for (int i = 1; i <= m; ++i)
    {
        std::cout << -Ans[i] << std::endl;  // 题目要求输出的是相反数，别被坑到了
    }

    return 0;
}