// 排序然后遍历一遍即可
#include <iostream>
#include <algorithm>
#include <array>

using ll = long long;

int main()
{
    constexpr auto MaxN = 1000 + 5;
    std::array<int, MaxN> Arr{ 0 };

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> Arr[i];
    }
    std::sort(Arr.begin(), Arr.begin() + n);

    ll Sum = 0;
    for (int i = 1; i < n; ++i)
    {
        if (Arr[i] - Arr[i - 1] != 1)   // 找到不连续的数字（相差大于一），就加上它们中间缺少的那些
        {
            Sum += Arr[i] - Arr[i - 1] - 1;
        }
    }
    std::cout << Sum << std::endl;

    return 0;
}