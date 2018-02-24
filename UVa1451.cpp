// 这一题的更详细的解释还是得看紫书P243
// 我这里只是给出其中一种按书上思路的实现并且附上详尽的注释
// 希望能对大家理解这一题有一点点的帮助
#include <iostream>
#include <array>
#include <string>

constexpr int MaxN = 100000 + 5;
std::array<int, MaxN> Sum{ 0 }, p{ 0 };

// 比较k-p2p1和k-p4p3的斜率大小
// 用了乘法是因为交叉相乘了，变一下形即可
int CompareAverage(int x1, int x2, int x3, int x4)
{
    return (Sum[x2] - Sum[x1 - 1]) * (x4 - x3 + 1)
        - (Sum[x4] - Sum[x3 - 1]) * (x2 - x1 + 1);
}

int main()
{
    int n, L, T;
    std::string s;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> L >> s;

        // 计算s[i]的前缀和
        Sum[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            Sum[i] = Sum[i - 1] + s[i - 1] - '0';
        }

        // p[i..j)是左端点的序列，这是一个单调队列
        int AnsL = 1, AnsR = L;
        int i = 0, j = 0;   // i是队头，j是队尾
        for (int t = L; t <= n; ++t)    // 以t作为线段的右端点
        {
            // 删除所有的上凸点：
            // 取出队尾两个点，比较它们和t - L的斜率大小
            // 发现上凸就弹出队尾元素，维护单调性
            while (j - i > 1 && CompareAverage(p[j - 2], t - L, p[j - 1], t - L) >= 0)
            {
                --j;
            }
            p[j++] = t - L + 1; // 入队，同时队尾加一

                                // i是线段左端点的在p[]中的下标
                                // 如果p[i]-p[i + 1]-t下凸，则p[i]不够p[i + 1]优
                                // 那就弹出队头
            while (j - i > 1 && CompareAverage(p[i], t, p[i + 1], t) <= 0)
            {
                ++i;
            }

            // 如果斜率更大或者斜率相同但区间更小
            // 就更新答案
            int c = CompareAverage(p[i], t, AnsL, AnsR);
            if (c > 0 || c == 0 && t - p[i] < AnsR - AnsL)
            {
                AnsL = p[i];
                AnsR = t;
            }
        }

        std::cout << AnsL << ' ' << AnsR << std::endl;
    }

    return 0;
}