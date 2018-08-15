// 比较基础的字符串匹配题目
// 预处理两发
// 第一发KMP匹配一次，找出所有匹配到的起始点
// 第二发前缀和算一遍，方便后续询问
#include <iostream>
#include <string>
#include <array>

std::array<int, 10000 + 5> f{ 0 }, Pos{ 0 }, Sum{ 0 };

int n, m, q;

void GetFail(const std::string &P)
{
    for (std::size_t i = 1; i < P.size(); ++i)
    {
        auto j = f[i];
        while (j && P[i] != P[j])
        {
            j = f[j];
        }
        f[i + 1] = P[i] == P[j] ? j + 1 : 0;
    }
}

void Find(const std::string &T, const std::string &P)
{
    GetFail(P);
    std::size_t j = 0;
    for (std::size_t i = 0; i < T.size(); ++i)
    {
        while (j && P[j] != T[i])
        {
            j = f[j];
        }
        if (P[j] == T[i])
        {
            ++j;
        }
        if (j == P.size())
        {
            Pos[i - P.size() + 2] = 1;  // KMP改一下这里就好了，标记一下匹配到的起始点
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m >> q;

    std::string T, P;
    std::cin >> T >> P;

    Find(T, P); // KMP预处理一次

    for (int i = 1; i <= n; ++i)    // 前缀和再预处理一次
    {
        Sum[i] = Sum[i - 1] + Pos[i];
    }

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        if (r - l + 1 < m)  // 如果查询的区间连一个待查询串都容不下，肯定输出0
        {
            std::cout << 0 << std::endl;
        }
        else    // 否则就按照前缀和来计算，注意中间加加减减的不要手抖打错了
        {
            std::cout << Sum[r - m + 1] - Sum[l - 1] << std::endl;
        }
    }

    return 0;
}