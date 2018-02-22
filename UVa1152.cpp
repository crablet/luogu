#include <iostream>
#include <algorithm>
#include <array>

using ll = long long;

constexpr int MaxN = 4000 + 5;
int n, c;
std::array<int, MaxN> A{ 0 }, B{ 0 }, C{ 0 }, D{ 0 };
std::array<int, MaxN * MaxN> Sums{ 0 }; // 存放A[i]和B[j]两两相加的和

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> A[i] >> B[i] >> C[i] >> D[i];
        }

        // 这一题的思路十分直白：
        // 就是把每一组(A[i] + B[j])的组合都算出来，
        // 然后存在Sums[]中，
        // 接着对Sums[]排序，
        // 然后寻找每一组(-C[i] - D[j])在Sums[]中出现了多少次，把这些次数都加起来，
        // 相加后的结果即是答案

        c = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                Sums[c++] = A[i] + B[j];    // A[i]和B[j]两两相加
            }
        }
        std::sort(Sums.begin(), Sums.begin() + c); // 排序，为了后面二分方便

        ll cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 其实就是在找Sums[]中有多少个连续的(-C[i] - D[j])，然后加起来
                cnt += std::upper_bound(Sums.cbegin(), Sums.cbegin() + c, -C[i] - D[j])
                     - std::lower_bound(Sums.cbegin(), Sums.cbegin() + c, -C[i] - D[j]);
            }
        }

        std::cout << cnt << std::endl;

        if (T)
        {
            std::putchar('\n');
        }
    }

    return 0;
}