// 这一题利用了类似动态规划的思想
// 枚举每一种合法的情况，然后统计概率和
// 用一下记忆化搜索，降低搜索次数
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>

std::map<std::vector<int>, double> d;
std::array<std::array<std::string, 4>, 9> Card;

// cnt：牌的情况
// c：一共还有c张牌
double DP(std::vector<int> &cnt, int c)
{
    if (c == 0)
    {
        return 1.0;
    }

    if (d.count(cnt) != 0)  // 记忆化搜索
    {
        return d[cnt];
    }

    double Sum = 0.0;
    int Tot = 0;
    for (int i = 0; i < 9; ++i) // 枚举每一堆牌
    {
        if (cnt[i] > 0) // 如果还剩下牌
        {
            for (int j = i + 1; j < 9; ++j)
            {
                if (cnt[j] > 0)
                {
                    // 那就比较一下堆顶的牌是否面值一样
                    // 取首字母就好了，因此是[0]
                    if (Card[i][cnt[i] - 1][0] == Card[j][cnt[j] - 1][0])
                    {
                        ++Tot;  // 统计取了多少次
                        --cnt[i];   // 拿走
                        --cnt[j];

                        Sum += DP(cnt, c - 2);  // 统计概率

                        ++cnt[i];   // 放回去，回溯
                        ++cnt[j];
                    }
                }
            }
        }
    }

    if (Tot == 0)
    {
        return d[cnt] = 0;  // 记忆化
    }
    else
    {
        return d[cnt] = Sum / Tot;  // 记忆化
    }
}

bool Read()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (!(std::cin >> Card[i][j]))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    while (Read())
    {
        // cnt[i]表示第i堆牌里面还剩下多少张
        // 初始时为9堆牌，每堆4张
        std::vector<int> cnt(9, 4);
        d.clear();
        std::printf("%.6lf\n", DP(cnt, 36));
    }

    return 0;
}