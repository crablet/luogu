// ²Î¿¼²©¿Í£ºhttps://blog.csdn.net/weixin_41156591/article/details/81507243
#include <iostream>
#include <array>
#include <algorithm>

using ll = long long;

constexpr int MaxN = 300000 + 5;

std::array<ll, MaxN> a{ 0 }, b{ 0 }, SumPre{ 0 }, SumL{ 0 }, SumR{ 0 };
std::array<ll, MaxN * 2> SumS{ 0 }, SumN{ 0 };

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> b[i];
    }

    for (int i = n; i >= 1; --i)
    {
        SumPre[i] = SumPre[i + 1] + a[i] + b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        SumS[i] = SumS[i - 1] + a[i] * (i - 1);
        SumN[i] = SumN[i - 1] + b[i] * (i - 1);
    }
    for (int i = n; i >= 1; --i)
    {
        SumS[2 * n + 1 - i] = SumS[2 * n - i] + b[i] * (2 * n - i);
        SumN[2 * n + 1 - i] = SumN[2 * n - i] + a[i] * (2 * n - i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 == 1)
        {
            SumR[i] = SumS[2 * n + 1 - i] - SumS[i - 1] + (i - 1) * SumPre[i];
            SumL[i] = SumL[i - 1] + a[i - 1] * (2 * i - 3) + b[i - 1] * (2 * i - 4);
        }
        else
        {
            SumR[i] = SumN[2 * n + 1 - i] - SumN[i - 1] + (i - 1) * SumPre[i];
            SumL[i] = SumL[i - 1] + a[i - 1] * (2 * i - 4) + b[i - 1] * (2 * i - 3);
        }
    }

    ll Ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        Ans = std::max(Ans, SumL[i] + SumR[i]);
    }
    std::cout << Ans << std::endl;

    return 0;
}