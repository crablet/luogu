// 这一题考的是最小生成树
// 具体的解释还是看紫书P358比较好
// 我只是代码的搬运工，并且写一点注释供大家参考
// 希望能对大家理解这一题提供一点点的帮助
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

constexpr int MaxN = 1000 + 10;
constexpr int MaxQ = 8;

int n;
std::array<int, MaxN> x{ 0 }, y{ 0 }, p{ 0 };
std::array<int, MaxQ> Cost{ 0 };
std::array<std::vector<int>, MaxQ> SubN;

int Find(int x)
{
    return p[x] != x ? p[x] = Find(p[x]) : x;
}

class Edge
{
public:
    int u, v, d;

    Edge() = default;
    Edge(int u, int v, int d) :
        u(u), v(v), d(d)
    {
    }
};

// cnt：还剩多少个点没有联通
// e：边的集合
// Used：已经联通的边
template <typename T>
int MST(int cnt, const T &e, T &Used)
{
    if (cnt == 1)
    {
        return 0;
    }

    int Ans = 0;
    Used.clear();
    for (std::size_t i = 0; i < e.size(); ++i)  // Kruskal
    {
        int u = Find(e[i].u), v = Find(e[i].v);
        if (u != v)
        {
            p[u] = v;
            Ans += e[i].d;
            Used.push_back(e[i]);   // 在第一次调用Kruskal时，Used被用来求生成树

            if (--cnt == 1)
            {
                break;
            }
        }
    }

    return Ans;
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

int main()
{
    int T;
    std::cin >> T;  // 共T组数据
    while (T--)
    {
        int q;
        n = Read(); // 有n条边
        q = Read(); // 有q种套餐
        for (int i = 0; i < q; ++i)
        {
            int cnt;    // 这个套餐能连cnt个点
            cnt = Read();
            Cost[i] = Read();   // 该套餐的花费

            SubN[i].clear();    // 因为有多组数据，所以要记得清空
            while (cnt--)
            {
                int u;
                u = Read();
                SubN[i].push_back(u - 1);   // 记录套餐i能连的边
            }
        }
        for (int i = 0; i < n; ++i) // 记录每个点的(x, y)坐标
        {
            x[i] = Read();
            y[i] = Read();
        }

        std::vector<Edge> e;
        for (int i = 0; i < n; ++i) // 生成整张图的点边信息
        {
            for (int j = i + 1; j < n; ++j)
            {
                int c = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                e.emplace_back(i, j, c);
            }
        }

        // 排序，为Kruskal做准备
        std::sort(e.begin(), e.end(), [](const Edge &a, const Edge &b)
        {
            return a.d < b.d;
        });

        for (int i = 0; i < n; ++i)
        {
            p[i] = i;
        }
        std::vector<Edge> Need; // 求最小生成树里有什么边
        int Ans = MST(n, e, Need);  // 在没使用套餐之前先求一次最小生成树
        for (int Mask = 0; Mask < (1 << q); ++Mask) // 枚举每个套餐的使用情况
        {                                           // 看不懂位运算的可以先去看一下状压
            for (int i = 0; i < n; ++i) // 每次都重新初始化一次并查集
            {
                p[i] = i;
            }

            int cnt = n, c = 0;
            for (int i = 0; i < q; ++i)
            {
                if (Mask & (1 << i))    // 检验用不用i套餐
                {
                    c += Cost[i];   // c是总经费
                    for (std::size_t j = 1; j < SubN[i].size(); ++j)
                    {
                        // 把该套餐中的边都加入生成树中
                        int u = Find(SubN[i][j]), v = Find(SubN[i][0]);
                        if (u != v)
                        {
                            p[u] = v;
                            --cnt;
                        }
                    }
                }
            }

            std::vector<Edge> Dummy;    // 没什么用的变量
            Ans = std::min(Ans, c + MST(cnt, Need, Dummy));
        }

        std::cout << Ans << std::endl;
        if (T)
        {
            std::putchar('\n');
        }
    }

    return 0;
}