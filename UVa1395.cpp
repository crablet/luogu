// 首先按权值把边从小到大排序
// 然后我们不断地向并查集里面加入新的边
// 一开始加入的边为L，最后加入的边为R
// 类似Krushal，直到所有边都联通了为止
// 然后计算d[R] - d[L]，更新答案，L向前推进
// 再把R重置为L，重复上面的过程直到走到底
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

constexpr int MaxN = 100 + 10;
constexpr int INF = 999999999;

int n, m;   // n：点的个数   m：边的个数
std::array<int, MaxN> p{ 0 };

// 并查集的查找操作
int Find(int x)
{
    if (p[x] == x)
    {
        return x;
    }
    else
    {
        return p[x] = Find(p[x]);
    }
}

// 快读
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

class Edge
{
public:
    int u, v, d;

    Edge() = default;
    Edge(int u, int v, int d) : // 从u到v有一条权值为d的无向边
        u(u), v(v), d(d)
    {
    }
};

std::vector<Edge> e;

int Solve()
{
    // 首先把边按权值从小到大排序
    std::sort(e.begin(), e.end(), [](const Edge &a, const Edge &b)
    {
        return a.d < b.d;
    });

    int Ans = INF;
    for (int L = 0; L < m; ++L)
    {
        for (int i = 1; i <= n; ++i)
        {
            p[i] = i;   // 初始化并查集
        }

        auto cnt = n;
        for (int R = L; R < m; ++R)
        {
            auto u = Find(e[R].u);
            auto v = Find(e[R].v);
            if (u != v) // 如果不在一个集合里
            {
                p[u] = v;   // 那就加入并查集
                --cnt;
                if (cnt == 1)   // 如果已经联通了，那就更新一下答案，立即退出循环
                {
                    Ans = std::min(Ans, e[R].d - e[L].d);
                    break;
                }
            }
        }
    }

    return (Ans == INF ? -1 : Ans);
}

int main()
{
    while (std::cin >> n >> m && n)
    {
        e.clear();
        for (int i = 0; i < m; ++i)
        {
            int u, v, d;
            u = Read();
            v = Read();
            d = Read();
            e.emplace_back(u, v, d);
        }

        std::cout << Solve() << std::endl;
    }

    return 0;
}