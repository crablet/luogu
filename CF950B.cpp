// 看了一下数据范围，就直接暴力模拟吧
// 虽然过得很不好看，因为运行时间有点长（873ms），但是过了不是（滑稽）
// 具体见代码吧，像这样暴力的话，这题难度大概“普及-”
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using ll = long long;

ll Pri[100000 + 50], Num[100000 + 50];

ll Read()
{
    ll n = 0;
    char ch = std::getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = std::getchar();
    }

    while (ch <= '9' && ch >= '0')
    {
        n = n * 10 + ch - '0';
        ch = std::getchar();
    }

    return n;
}

int main()
{
    ll n, k, m;
    std::cin >> n >> k >> m;
    std::unordered_map<std::string, ll> Map;    // <词语名称, 编号>
    std::string Str;
    for (ll i = 1; i <= n; ++i)
    {
        std::cin >> Str;
        Map[Str] = i;   // 记下每个词语的编号
    }

    for (ll i = 1; i <= n; ++i)
    {
        Pri[i] = Read();
    }

    for (ll i = 1; i <= k; ++i)
    {
        ll p, Min = 999999999 + 50;
        p = Read();
        for (ll i = 1; i <= p; ++i)
        {
            Num[i] = Read();
            if (Pri[Num[i]] < Min)  // 记下同类型词语当中花费最小的那个的价格
            {
                Min = Pri[Num[i]];
            }
        }

        for (ll i = 1; i <= p; ++i)
        {
            Pri[Num[i]] = Min;  // 然后只要将同类型的词语的花费全都设为最小的即可
        }
    }

    ll Sum = 0; // 因为同类型的词语的当前花费都变成最小的了，所以直接查询目前词语就好了
    for (ll i = 1; i <= m; ++i)
    {
        std::cin >> Str;
        Sum += Pri[Map[Str]];
    }

    std::cout << Sum << std::endl;

    return 0;
}