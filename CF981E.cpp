// dp题，详解看代码及我的注释，希望能对大家有所帮助
#include <iostream>
#include <array>
#include <tuple>
#include <algorithm>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<std::tuple<int, int, int>> Q;   // 端点对<l, r, x>的集合
    for (int i = 0; i < q; ++i)
    {
        int l, r, x;
        std::cin >> l >> r >> x;
        Q.push_back({ l, r, x });
    }
    std::sort(Q.begin(), Q.end(), [](const auto &l, const auto &r) // 按右端点从小到大进行排序
    {
        return std::get<1>(l) < std::get<1>(r);
    });

    constexpr int MaxN = 10000 + 5;
    std::array<int, MaxN> dp{ 0 };

    // dp[i]表示数字i能够达到的最右边的端点位置，如果数字i无法取得则为0
    // 起始状态是dp[0] = n，因为一开始全是0，0本身就能达到最右的端点n
    dp[0] = n;
    for (int i = 0; i < q; ++i) // 排序之后遍历每一个区间
    {
        const auto &[l, r, x] = Q[i];

        for (int j = n; j >= x; --j)    // 由于不能超过n，所以从n往下循环，但到底的时候j - x不能小于零，因此下界是x
        {
            if (dp[j - x] >= l) // 如果左端点小于j - x能在的最右位置，说明j - x有可能被这个加上的x更新。然后我们有两种更新方式：
            {
                if (dp[j - x] <= r) // 如果当前区间能够包含j - x所在的最右端点，说明j - x可以被更新为j，那么就看一下更新之后是否能延申j的最右端
                {
                    dp[j] = std::max(dp[j], dp[j - x]);
                }
                else // 如果当前区间不能包含j - x，那就看看能不能更新x的位置，由于r以按从小到大排序，所以直接赋值r就行了，它是递增的
                {
                    dp[x] = r;
                }
            }
        }
    }

    int Ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i])  // 统计能达到的数字有多少个，因为按照原先的约定，无法取得的数字右端点被设为了0
        {
            ++Ans;
        }
    }

    // 按题意输出
    std::cout << Ans << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i])
        {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}