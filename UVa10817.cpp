// 首先先了解一下位运算的一些基本操作：
// &：表示一个元素是否在这个集合里
// |：表示将这个元素加入这个集合中
// ^：表示将这个元素从这个集合中删除
// 然后我们就用二进制数的每一位表示一个科目的状态
// 最后就是简单的dp，难点在于对各个科目状态的表达
// 详见代码和注释
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>

constexpr int MaxN = 100 + 20 + 5;
constexpr int MaxS = 8;
constexpr int INF = 1000000000;

int m, n, s, c[MaxN], st[MaxN], d[MaxN][1 << MaxS][1 << MaxS];

// dp(i, s0, s1, s2)表示：
// 已经考虑了前i个人，还剩s0种没人会的科目，s1种一人会的科目，s2种两人以上会的科目
int dp(int i, int s0, int s1, int s2)
{
    if (i == m + n) // 搜完了所有的人了
    {   // 如果s2还没满的话，那就说明不可能满足了
        return s2 == (1 << s) - 1 ? 0 : INF;
    }

    int &Ans = d[i][s1][s2];
    if (Ans >= 0)   // 记忆化搜索的体现，因为没被搜过的时候是-1
    {
        return Ans;
    }

    Ans = INF;  // 没被搜过，就先初始化一下，设为INF
    if (i >= m)
    {
        // 在可选的情况下却不选i。先算出不选i的结果，等待后面与选i的的结果比较。
        Ans = dp(i + 1, s0, s1, s2);
    }

    // 下面是选i的情况：
    // m0：在st[i]中没人会的，但i会的
    // m1：在st[i]中只有一个人会的，i也会的
    int m0 = st[i] & s0, m1 = st[i] & s1;
    s0 ^= m0;   // 在s0中消除那些i会的
    s1 = (s1 ^ m1) | m0;    // 在已经有一个人会的技能里面减去i会的，
                            // 因为不减的话就是两个人会了
                            // 然后再加上i独有的会的，就成了新的一人会的集合
    s2 |= m1;   // 在s2中加上m1，表示现在有两个人会的有这么多
    Ans = std::min(Ans, c[i] + dp(i + 1, s0, s1, s2));  // 看是选i贵还是不选i贵

    return Ans;
}

int main()
{
    int x;
    std::string Line;
    while (std::getline(std::cin, Line))
    {
        std::stringstream ss(Line);
        ss >> s >> m >> n;  // 共s个科目，m名在职，n名应聘
        if (s == 0)
        {
            break;
        }

        for (int i = 0; i < m + n; ++i)
        {
            std::getline(std::cin, Line);
            std::stringstream ss(Line);
            ss >> c[i]; // 第i人所需要的工资
            st[i] = 0;  // 他能教的科目先设为空
            while (ss >> x)
            {
                st[i] |= (1 << (x - 1));    // 添加进去他所能教的科目集合里面
            }                               // 减一是因为输入中的编号从1开始
        }

        std::memset(d, -1, sizeof(d));  // 表示还没有被搜过
        std::cout << dp(0, (1 << s) - 1, 0, 0) << std::endl;
    }             // 初始搜时所有科目都没人教，从0号开始搜

    return 0;
}