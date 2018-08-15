// 一道构造题，比赛的时候没有弄出来，去想怎么解方程组去了，当时就应该老老实实开脑洞想构造来着
// 首先，利用异或的性质，如果矩阵中每个元素都被异或两边，那么最后的异或和肯定为0
// 然后，我们就可以开脑洞构造了：
// 首先，除了最后一行和最后一列的元素都设为0
// 接着，除了右下角那最后一个元素，其余还没被赋值的地方的元素都设为那一行（列）的异或和
// 右下角的那个元素也可以通过异或的性质推出来
#include <iostream>
#include <array>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    constexpr int MaxN = 100 + 5;
    std::array<int, MaxN> a{ 0 }, b{ 0 };

    int n, m, Ans = 0;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        Ans ^= a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
        Ans ^= b[i];
    }

    if (Ans != 0)   // 检验一下所有元素两边异或之后的结果是不是0，不是则证明无解
    {
        std::cout << "NO" << std::endl;
    }
    else
    {
        std::cout << "YES" << std::endl;

        Ans = b[m - 1]; // 先存一下最后一列的异或和，为了推出右下角的那个元素

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < m - 1; ++j)
            {
                std::cout << 0 << ' ';  // 除了最后一行和最后一列，其余地方都是0
            }
            std::cout << a[i] << std::endl; // 最后一列的元素

            Ans ^= a[i];    // 根据最后一列的异或和推出右下角那个元素
        }

        for (int i = 0; i < m - 1; ++i)
        {
            std::cout << b[i] << ' ';   // 最后一行的元素
        }
        std::cout << Ans << std::endl;  // 右下角的元素
    }

    return 0;
}