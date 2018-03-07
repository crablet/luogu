// 枚举每个人买不买东西，
// 然后把每个人自己买东西的概率加起来，
// 最后和总的可能的概率再做个除法
#include <iostream>
#include <array>
#include <bitset>
#include <algorithm>

constexpr int MaxN = 20 + 5;
int n, r;   // 一共有n个人，r人买了东西
std::bitset<MaxN> Buy;  // 标记第i个人买不买东西
std::array<double, MaxN> P{ 0 }, Sum{ 0 };
// P[i]表示第i个人买东西的概率，Sum[i]表示第i个人买东西的概率之和

// d：搜索深度
// c：几个人去买了产品
// prob：概率
void DFS(int d, int c, double prob)
{
    // 如果已经大于r个人买东西或者没买东西的人差太多了都赶不上了
    if (c > r || d - c > n - r)
    {
        return;
    }

    if (d == n) // 搜完了n个人（从0开始搜的）
    {
        Sum[n] += prob; // Sum[n]表示Sum[i(0 .. n - 1)]之和
        for (int i = 0; i < n; ++i)
        {
            if (Buy[i]) // 如果第i个人买东西了，那就记录下这个概率，然后加和
            {
                Sum[i] += prob;
            }
        }

        return;
    }

    Buy[d] = false;
    DFS(d + 1, c, prob * (1 - P[d]));   // 第d个人不买
    Buy[d] = true;
    DFS(d + 1, c + 1, prob * P[d]);     // 第d个人买
}

int main()
{
    int NO = 0;
    while (std::cin >> n >> r && n)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cin >> P[i];
        }
        std::fill(Sum.begin(), Sum.end(), 0);

        DFS(0, 0, 1.0);

        std::cout << "Case " << ++NO << ":" << std::endl;
        for (int i = 0; i < n; ++i)
        {
            std::printf("%.6lf\n", Sum[i] / Sum[n]);
        }
    }

    return 0;
}