// 看这题的数据量似乎不算太大
// 所以不用DP也可以
// 直接上DFS也不会超时
// 这个做法比较暴力但是容易想到
// 具体看代码
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

int n, a, b;
std::array<int, 100> h{ 0 };
std::vector<int> Vec, Temp;

int Ans = INT_MAX;

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

// DFS(Now, Sum)表示：
// 能打败前Now - 1个弓箭手需要最少打Sum发
void DFS(int Now, int Sum)
{
    if (Sum >= Ans) // 剪枝
    {
        return;
    }

    if (Now == n - 1)   // 搜完了，因为最后一个人不能直接打，只能被间接打
    {
        if (h[n - 1] < 0)   // 如果最后一个也被打死了，那就可以更新答案
        {
            Ans = Sum;
            Vec = Temp;
        }

        return;
    }

    // 否则就取肯定能打败其中一个的方案进行DFS
    for (int i = 0;
        i <= std::max({ (h[Now - 1] / b), (h[Now] / a), (h[Now + 1] / b) }) + 1;
        ++i)
    {
        if (h[Now - 1] - b * i < 0) // 如果能打败最左边的那一个，满足我们DFS的要求
        {
            h[Now - 1] -= b * i;    // 那就试一下释放攻击
            h[Now] -= a * i;        // 注意，三个人都会受伤
            h[Now + 1] -= b * i;
            for (int t = 0; t < i; ++t)
            {
                Temp.push_back(Now + 1);
            }

            DFS(Now + 1, Sum + i);  // 往下搜下一个

            h[Now - 1] += b * i;    // 回溯
            h[Now] += a * i;
            h[Now + 1] += b * i;
            for (int t = 0; t < i; ++t)
            {
                Temp.pop_back();
            }
        }
    }

    return;
}

int main()
{
    n = Read();
    a = Read();
    b = Read();
    for (int i = 0; i < n; ++i)
    {
        h[i] = Read();
    }

    // 我们从0开始编号，注意第一个和最后一个人不能直接打
    DFS(1, 0);

    std::cout << Ans << std::endl;
    for (const auto &r : Vec)
    {
        std::cout << r << ' ';
    }
    std::putchar('\n');

    return 0;
}